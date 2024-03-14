#include <cstdio>
#include <memory>
#include <cmath>
#include <rclcpp/rclcpp.hpp>
#include "rclcpp_action/rclcpp_action.hpp"

#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

#include <geometric_shapes/shape_operations.h>
#include <moveit_msgs/msg/collision_object.hpp>

#include "project_messages/action/pick_or_place.hpp"


struct GraspPoses {
    geometry_msgs::msg::Pose pre_grasp;
    geometry_msgs::msg::Pose grasp;
    geometry_msgs::msg::Pose release;
};

using moveit::planning_interface::MoveGroupInterface;
// using namespace moveit::task_constructor;

GraspPoses calculateGraspPoses(const geometry_msgs::msg::Pose& block_position);

class PickOrPlaceActionServer : public rclcpp::Node
{
public:
  using ActionPickOrPlace = project_messages::action::PickOrPlace;
  using GoalHandle = rclcpp_action::ServerGoalHandle<ActionPickOrPlace>;
  using MoveitGroupInterface = moveit::planning_interface::MoveGroupInterface;
  
  explicit PickOrPlaceActionServer(const rclcpp::NodeOptions & options = rclcpp::NodeOptions())
  : Node("arm_pick_or_place_server", options)
  {
      using namespace std::placeholders;
      printf("Pick or Place Server Started!\n");

      this->action_server_ = rclcpp_action::create_server<ActionPickOrPlace>(
        this,
        "arm_pick_or_place",
        std::bind(&PickOrPlaceActionServer::handle_goal, this, _1, _2),
        std::bind(&PickOrPlaceActionServer::handle_cancel, this, _1),
        std::bind(&PickOrPlaceActionServer::handle_accepted, this, _1)
      );
      
      // Create the move group node
      move_group_node = std::make_shared<rclcpp::Node>(
        "locobot_moveit",
        rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true)
      );
  }

private:
  rclcpp_action::Server<ActionPickOrPlace>::SharedPtr action_server_;
  std::shared_ptr<rclcpp::Node> move_group_node;

  rclcpp_action::GoalResponse handle_goal(
      const rclcpp_action::GoalUUID & uuid,
      [[maybe_unused]] std::shared_ptr<const ActionPickOrPlace::Goal> goal)
  {
      RCLCPP_INFO(this->get_logger(), "Received goal request");
      (void)uuid;
      return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }

  rclcpp_action::CancelResponse handle_cancel(
      const std::shared_ptr<GoalHandle> goal_handle)
  {
      RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
      (void)goal_handle;
      return rclcpp_action::CancelResponse::ACCEPT;
  }

  void handle_accepted(const std::shared_ptr<GoalHandle> goal_handle)
  {
      using namespace std::placeholders;
      // this needs to return quickly to avoid blocking the executor, so spin up a new thread
      std::thread{std::bind(&PickOrPlaceActionServer::execute, this, _1), goal_handle}.detach();
  }

  void execute(const std::shared_ptr<GoalHandle> goal_handle)
  {
    RCLCPP_INFO(this->get_logger(), "Executing goal");
    auto goal = goal_handle->get_goal();
    auto result = std::make_shared<ActionPickOrPlace::Result>();
    
    auto node_shared_ptr = std::static_pointer_cast<rclcpp::Node>(shared_from_this());
    
    MoveGroupInterface move_group_interface_arm(node_shared_ptr, "interbotix_arm");
    MoveGroupInterface move_group_interface_gripper(node_shared_ptr, "interbotix_gripper");
    
    // Set a target Pose
    geometry_msgs::msg::Pose target_pose;
    //position 
    target_pose.position.x = goal->pose[0];
    target_pose.position.y = goal->pose[1];
    target_pose.position.z = goal->pose[2];
    //orientation
    target_pose.orientation.x = 0.0;
    target_pose.orientation.y = 0.0;
    target_pose.orientation.z = 0.0;
    target_pose.orientation.w = 1.0;
    
    GraspPoses poses = calculateGraspPoses(target_pose);
    
    if(goal->pick_or_place) { // pick_or_place = true means pick
      // Calculate grasp poses (pre_grasp and grasp)
      addCubeToScene(target_pose);
      addBoxToScene(0.02);
      [[maybe_unused]] bool gripper_open_success = planAndMoveToNamedTarget(move_group_interface_gripper, "Released");
      [[maybe_unused]] bool move_to_pre_grasp_success = planAndMoveToPose(move_group_interface_arm, poses.pre_grasp);
      removeBoxFromScene();
      addBoxToScene(0.0);
      [[maybe_unused]] bool move_to_grasp_success = planAndMoveToPose(move_group_interface_arm, poses.grasp);
      removeCubeFromScene();
      [[maybe_unused]] bool gripper_close_success = planAndMoveToNamedTarget(move_group_interface_gripper, "Home");
      removeBoxFromScene();
    } else {
      // pick_or_place = false means place
      addBoxToScene(0.02);
      [[maybe_unused]] bool move_to_pre_grasp_success = planAndMoveToPose(move_group_interface_arm, poses.release);
      [[maybe_unused]] bool gripper_open_success = planAndMoveToNamedTarget(move_group_interface_gripper, "Released");
      removeBoxFromScene();
    }
    
    result->success = true;
    goal_handle->succeed(result);
    

    RCLCPP_INFO(this->get_logger(), "Pick or place completed.");
  }
  
  bool planAndMoveToPose(MoveGroupInterface& move_group_interface, geometry_msgs::msg::Pose& target_pose) 
  {
      move_group_interface.setPoseTarget(target_pose);

      // Plan to the target pose
      moveit::planning_interface::MoveGroupInterface::Plan plan;
      moveit::planning_interface::MoveItErrorCode planning_success = move_group_interface.plan(plan);

      if(planning_success == moveit::planning_interface::MoveItErrorCode::SUCCESS) {
          RCLCPP_INFO(this->get_logger(), "Planning succeded, executing...");
          moveit::planning_interface::MoveItErrorCode execution_success = move_group_interface.execute(plan);

          if(execution_success == moveit::planning_interface::MoveItErrorCode::SUCCESS) {
            RCLCPP_INFO(this->get_logger(), "Motion executed successfully.");
            return true;
          } else {
            RCLCPP_ERROR(this->get_logger(), "Motion execution failed. Error code: %d", execution_success.val);
            return false;
          }
      } else {
        RCLCPP_ERROR(this->get_logger(), "Planning failed, execution not attempted. Error code: %d", planning_success.val);
        return false;
      }
  }
  
  bool planAndMoveToNamedTarget(MoveGroupInterface& move_group_interface, const std::string& name) 
  {   
      move_group_interface.setNamedTarget(name);

      // Plan to the target pose
      moveit::planning_interface::MoveGroupInterface::Plan plan;
      moveit::planning_interface::MoveItErrorCode planning_success = move_group_interface.plan(plan);

      if(planning_success == moveit::planning_interface::MoveItErrorCode::SUCCESS) {
          RCLCPP_INFO(this->get_logger(), "Planning successed, executing...");
          moveit::planning_interface::MoveItErrorCode execution_success = move_group_interface.execute(plan);

          if(execution_success == moveit::planning_interface::MoveItErrorCode::SUCCESS) {
            RCLCPP_INFO(this->get_logger(), "Motion executed successfully.");
            return true;
          } else {
            RCLCPP_ERROR(this->get_logger(), "Motion execution failed. Error code: %d", execution_success.val);
            return false;
          }
      } else {
        RCLCPP_ERROR(this->get_logger(), "Planning failed, execution not attempted. Error code: %d", planning_success.val);
        return false;
      }
  }
  
  GraspPoses calculateGraspPoses(const geometry_msgs::msg::Pose& block_pose) 
  {
    GraspPoses poses;

    geometry_msgs::msg::Quaternion grasp_orientation;
    tf2::Quaternion q;
    float roll = (3.14159/180)*0.0;
    float pitch = (3.14159/180)*90.0;
    float yaw = (3.14159/180)*0.0;
    q.setRPY(roll, pitch, yaw);
    grasp_orientation = tf2::toMsg(q);

    // Set the same orientation for all poses
    poses.pre_grasp.orientation = grasp_orientation;
    poses.grasp.orientation = grasp_orientation;
    poses.release.orientation = grasp_orientation;

    // Adjust positions based on the block position
    // Pre-grasp pose: slightly above the block
    poses.pre_grasp.position.x = block_pose.position.x;
    poses.pre_grasp.position.y = block_pose.position.y;
    poses.pre_grasp.position.z = block_pose.position.z + 0.01; // 1 cm above

    // Grasp pose: at the block's position (adjust z if needed to match your gripper's characteristics)
    poses.grasp.position.x = block_pose.position.x;
    poses.grasp.position.y = block_pose.position.y;
    poses.grasp.position.z = block_pose.position.z + 0.006; // Assuming grasp at the block level

    // Release pose: slightly above the grasp pose
    poses.release.position.x = block_pose.position.x;
    poses.release.position.y = block_pose.position.y;
    poses.release.position.z = block_pose.position.z + 0.04; // 4 cm above, similar to pre-grasp

    return poses;
  }

  void addCubeToScene(const geometry_msgs::msg::Pose& block_pose)
  {
      moveit::planning_interface::PlanningSceneInterface planning_scene_interface;

      // Define the box dimensions and pose
      double depth = 0.017;  // Box height in meters
      double width = 0.017;  // Box width in meters
      double height = 0.017;  // Box length in meters

      // Define the collision object
      moveit_msgs::msg::CollisionObject collision_object;
      collision_object.header.frame_id = "locobot/base_link";  
      collision_object.id = "cube";

      shape_msgs::msg::SolidPrimitive primitive;
      primitive.type = primitive.BOX;
      primitive.dimensions = {width, height, depth};

      collision_object.primitives.push_back(primitive);
      collision_object.primitive_poses.push_back(block_pose);
      collision_object.operation = collision_object.ADD;

      // Add the box to the planning scene
      std::vector<moveit_msgs::msg::CollisionObject> collision_objects;
      collision_objects.push_back(collision_object);
      planning_scene_interface.applyCollisionObjects(collision_objects);
  }

  void addBoxToScene(float z_offset)
  {
      moveit::planning_interface::PlanningSceneInterface planning_scene_interface;

      // Define the box dimensions and pose
      double depth = 0.1;  // Box height in meters
      double width = 3.0;  // Box width in meters
      double height = 3.0;  // Box length in meters
      geometry_msgs::msg::Pose box_pose;
      box_pose.orientation.w = 1.0;
      box_pose.position.x = 0.0;
      box_pose.position.y = 0.0;
      box_pose.position.z = z_offset - (depth / 2.0);  // Center the box at z=0

      // Define the collision object
      moveit_msgs::msg::CollisionObject collision_object;
      collision_object.header.frame_id = "locobot/base_link";  // Adjust according to your frame
      collision_object.id = "box";

      shape_msgs::msg::SolidPrimitive primitive;
      primitive.type = primitive.BOX;
      primitive.dimensions = {width, height, depth};

      collision_object.primitives.push_back(primitive);
      collision_object.primitive_poses.push_back(box_pose);
      collision_object.operation = collision_object.ADD;

      // Add the box to the planning scene
      std::vector<moveit_msgs::msg::CollisionObject> collision_objects;
      collision_objects.push_back(collision_object);
      planning_scene_interface.applyCollisionObjects(collision_objects);
  }
  
  void removeBoxFromScene() 
  {
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;

    std::vector<std::string> object_ids;
    object_ids.push_back("box");  

    // Remove the box from the planning scene
    planning_scene_interface.removeCollisionObjects(object_ids);

    // Small delay to ensure the removal is processed
    rclcpp::sleep_for(std::chrono::milliseconds(1000));
}

void removeCubeFromScene() 
  {
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;

    std::vector<std::string> object_ids;
    object_ids.push_back("cube");  

    // Remove the box from the planning scene
    planning_scene_interface.removeCollisionObjects(object_ids);

    // Small delay to ensure the removal is processed
    rclcpp::sleep_for(std::chrono::milliseconds(1000));
}

  
};  // class PickOrPlaceActionServer

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  auto action_server = std::make_shared<PickOrPlaceActionServer>();
  rclcpp::spin(action_server);

  rclcpp::shutdown();
  return 0;
}