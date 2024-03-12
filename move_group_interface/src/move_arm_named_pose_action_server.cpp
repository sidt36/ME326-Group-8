#include <cstdio>
#include <memory>
#include <cmath>
#include <rclcpp/rclcpp.hpp>
#include "rclcpp_action/rclcpp_action.hpp"

#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <geometric_shapes/shape_operations.h>
#include <moveit_msgs/msg/collision_object.hpp>

#include "project_messages/action/move_arm_to_named_pose.hpp"

using moveit::planning_interface::MoveGroupInterface;

class MoveArmNamedPoseActionServer : public rclcpp::Node
{
public:
  using ActionMoveArm = project_messages::action::MoveArmToNamedPose;
  using GoalHandle = rclcpp_action::ServerGoalHandle<ActionMoveArm>;
  using MoveitGroupInterface = moveit::planning_interface::MoveGroupInterface;

  explicit MoveArmNamedPoseActionServer(const rclcpp::NodeOptions & options = rclcpp::NodeOptions())
  : Node("move_arm_named_pose_server", options)
  {
      using namespace std::placeholders;
      printf("Server Started!\n");

      this->action_server_ = rclcpp_action::create_server<ActionMoveArm>(
        this,
        "move_arm_named_pose",
        std::bind(&MoveArmNamedPoseActionServer::handle_goal, this, _1, _2),
        std::bind(&MoveArmNamedPoseActionServer::handle_cancel, this, _1),
        std::bind(&MoveArmNamedPoseActionServer::handle_accepted, this, _1)
      );
      
      // Create the move group node
      move_group_node = std::make_shared<rclcpp::Node>(
        "locobot_moveit",
        rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true)
      );      
  }

private:
  rclcpp_action::Server<ActionMoveArm>::SharedPtr action_server_;
  std::shared_ptr<rclcpp::Node> move_group_node;

  rclcpp_action::GoalResponse handle_goal(
      const rclcpp_action::GoalUUID & uuid,
      [[maybe_unused]] std::shared_ptr<const ActionMoveArm::Goal> goal)
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
      std::thread{std::bind(&MoveArmNamedPoseActionServer::execute, this, _1), goal_handle}.detach();
  }

  void execute(const std::shared_ptr<GoalHandle> goal_handle)
  {
    RCLCPP_INFO(this->get_logger(), "Executing goal");
    auto goal = goal_handle->get_goal();
    auto result = std::make_shared<ActionMoveArm::Result>();
    
    addBoxToScene(0.02);
    
    // Set the target pose which is a named pose (string)
    if(planAndMoveToNamedTarget(goal->pose)) {
      RCLCPP_INFO(this->get_logger(), "Motion executed successfully!");
      result->success = true;
      goal_handle->succeed(result);
    } else {
      RCLCPP_ERROR(this->get_logger(), "MoveGroupInterface::execute() failed or timeout reached");
      result->success = false;
      goal_handle->abort(result);
    }
    
    removeBoxFromScene();

    RCLCPP_INFO(this->get_logger(), "Goal execution completed");
  }
  
  bool planAndMoveToNamedTarget(const std::string& name) 
  {
    auto node_shared_ptr = std::static_pointer_cast<rclcpp::Node>(shared_from_this());
      MoveGroupInterface move_group_interface(node_shared_ptr, "interbotix_arm");
      
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
  
};  // class MoveArmNamedPoseActionServer

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  auto action_server = std::make_shared<MoveArmNamedPoseActionServer>();
  rclcpp::spin(action_server);

  rclcpp::shutdown();
  return 0;
}