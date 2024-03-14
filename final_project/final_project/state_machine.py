#!/usr/bin/env python3
import time
import rclpy
import threading

import yaml
import os
from ament_index_python import get_package_share_directory

import tf_transformations

from rclpy.executors import Future
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from rclpy.executors import MultiThreadedExecutor
from rclpy.parameter import Parameter

import numpy as np
import tf2_ros
import tf2_geometry_msgs
from tf2_ros import Buffer, TransformListener
from std_msgs.msg import Float64MultiArray
from nav_msgs.msg import Odometry
from rclpy.qos import qos_profile_sensor_data

from gazebo_msgs.msg import ModelStates


from action_msgs.msg import GoalStatus
from action_client.move_base_client import MoveActionClient
from action_client.move_arm_named_pose_client import MoveArmNamedPoseActionClient
from action_client.pick_or_place_client import PickOrPlaceActionClient
from action_client.attach_client import AttachClient
from action_client.attach_client import DetachClient
from action_client.perception_client import PerceptionClient

from rclpy.qos import QoSProfile, QoSHistoryPolicy, QoSReliabilityPolicy, QoSDurabilityPolicy

custom_qos_profile = QoSProfile(
    history=QoSHistoryPolicy.KEEP_LAST,
    depth=15,
    reliability=QoSReliabilityPolicy.RELIABLE,
    durability=QoSDurabilityPolicy.VOLATILE
)

from tf2_msgs.msg import TFMessage


POSE_MSG = '/locobot/sim_ground_truth_pose'
POSE_MSG_TYPE = Odometry

OWN_BUILD = 'a_build_a'
OWN_BUILD_OPP = 'a_build_b'
OPP_BUILD = 'b_build_b'
OPP_BUILD_OPP = 'b_build_a'

PATTERN_OFFSET_Y = 0.175
PATTERN_OFFSET_X = 0.0

CAM_CMD_MSG = '/locobot/camera_controller/commands'
LIST_OF_POSITIONS = [
            'center_tr',
            'center_tl',
            'center_br',
            'center_bl',
            'a_build_a',
            'a_build_b',
            'b_build_a',
            'b_build_b'
            ]

class StateMachine(Node):
    def __init__(self):
        super().__init__('state_machine')
        self.logger = self.get_logger()
        
        self.declare_parameter('pattern_file_name', 'own_pattern.yaml')
        pattern_file_name = self.get_parameter('pattern_file_name').value
        pattern_file_name = os.path.join(get_package_share_directory('final_project'), 'pattern', pattern_file_name)
        self.logger.info(f"Pattern file name: {pattern_file_name}")
        with open(pattern_file_name, 'r') as file:
            block_pattern_data = yaml.safe_load(file)
            self.block_pattern = block_pattern_data['block_pattern']
        
        self.current_pose = None
        self.model_states = dict()
        
        self.center_tr_pose = None
        self.center_tl_pose = None
        self.center_br_pose = None
        self.center_bl_pose = None
        self.a_build_a_pose = None
        self.a_build_b_pose = None
        self.b_build_a_pose = None
        self.b_build_b_pose = None
        self.all_tags_found = False
        
        self.move_base_client = MoveActionClient()
        self.move_arm_named_client = MoveArmNamedPoseActionClient()
        self.pick_or_place_client = PickOrPlaceActionClient()
        self.attach_client = AttachClient()
        self.detach_client = DetachClient()
        self.perception_client = PerceptionClient()
        
        self.mobile_camera_publisher = self.create_publisher(Float64MultiArray, CAM_CMD_MSG, 1)
        
        self.create_subscription(PoseStamped, '/center_tr', self.center_tr_callback, 10)
        self.create_subscription(PoseStamped, '/center_tl', self.center_tl_callback, 10)
        self.create_subscription(PoseStamped, '/center_br', self.center_br_callback, 10)
        self.create_subscription(PoseStamped, '/center_bl', self.center_bl_callback, 10)
        self.create_subscription(PoseStamped, '/a_build_a', self.a_build_a_callback, 10)
        self.create_subscription(PoseStamped, '/a_build_b', self.a_build_b_callback, 10)
        self.create_subscription(PoseStamped, '/b_build_a', self.b_build_a_callback, 10)
        self.create_subscription(PoseStamped, '/b_build_b', self.b_build_b_callback, 10)
        
        self.create_subscription(
            ModelStates,
            '/gazebo/model_states',
            self.model_states_callback,
            qos_profile_sensor_data
        )
        
        self.create_subscription(POSE_MSG_TYPE, POSE_MSG, self.pose_callback, qos_profile_sensor_data)
        self.tf_buffer = Buffer(cache_time=rclpy.duration.Duration(seconds=5))
        self.tf_listener = TransformListener(self.tf_buffer, self, qos=50)
        
        self.main_logic_done_event = None

    def model_states_callback(self, msg):
        for i, name in enumerate(msg.name):
            self.model_states[name] = msg.pose[i]

    def pose_callback(self, msg):
        # self.logger.info(f"Received pose message: {msg.header.stamp}")
        self.current_pose = msg
    
    def set_april_poses(self):
        pose = PoseStamped()
        pose.header.frame_id = 'world'
        pose.header.stamp = self.get_clock().now().to_msg()
        pose.pose.position.x = 0.75
        pose.pose.position.y = 0.5
        self.center_tr_pose = pose
        
        pose = PoseStamped()
        pose.header.frame_id = 'world'
        pose.header.stamp = self.get_clock().now().to_msg()
        pose.pose.position.x = 1.0
        pose.pose.position.y = 0.5
        self.center_tl_pose = pose
        
        pose = PoseStamped()
        pose.header.frame_id = 'world'
        pose.header.stamp = self.get_clock().now().to_msg()
        pose.pose.position.x = 0.75
        pose.pose.position.y = -0.5
        self.center_br_pose = pose
        
        pose = PoseStamped()
        pose.header.frame_id = 'world'
        pose.header.stamp = self.get_clock().now().to_msg()
        pose.pose.position.x = 1.0
        pose.pose.position.y = -0.5
        self.center_bl_pose = pose
        
        pose = PoseStamped()
        pose.header.frame_id = 'world'
        pose.header.stamp = self.get_clock().now().to_msg()
        pose.pose.position.x = 0.0
        pose.pose.position.y = 0.75
        self.a_build_a_pose = pose
        
        pose = PoseStamped()
        pose.header.frame_id = 'world'
        pose.header.stamp = self.get_clock().now().to_msg()
        pose.pose.position.x = 0.0
        pose.pose.position.y = -0.75
        pose.pose.orientation.x = 0.0
        pose.pose.orientation.y = 0.0
        pose.pose.orientation.z = 1.0
        pose.pose.orientation.w = 0.0
        self.a_build_b_pose = pose
        
        pose = PoseStamped()
        pose.header.frame_id = 'world'
        pose.header.stamp = self.get_clock().now().to_msg()
        pose.pose.position.x = 1.75
        pose.pose.position.y = 0.75
        self.b_build_a_pose = pose
        
        pose = PoseStamped()
        pose.header.frame_id = 'world'
        pose.header.stamp = self.get_clock().now().to_msg()
        pose.pose.position.x = 1.75
        pose.pose.position.y = -0.75
        pose.pose.orientation.x = 0.0
        pose.pose.orientation.y = 0.0
        pose.pose.orientation.z = 1.0
        pose.pose.orientation.w = 0.0
        self.b_build_b_pose = pose
    
    def center_tr_callback(self, msg):
        self.center_tr_pose = msg
        
    def center_tl_callback(self, msg):
        self.center_tl_pose = msg
        
    def center_br_callback(self, msg):
        self.center_br_pose = msg
        
    def center_bl_callback(self, msg):
        self.center_bl_pose = msg
        
    def a_build_a_callback(self, msg):
        self.a_build_a_pose = msg
        
    def a_build_b_callback(self, msg):
        self.a_build_b_pose = msg
        
    def b_build_a_callback(self, msg):
        self.b_build_a_pose = msg
        
    def b_build_b_callback(self, msg):
        self.b_build_b_pose = msg
    
    def move_arm_named_pose(self, pose_name):
        self.move_arm_named_client.send_goal(pose_name)
        while (
            (self.move_arm_named_client.status != GoalStatus.STATUS_SUCCEEDED) and
            (self.move_arm_named_client.status != GoalStatus.STATUS_ABORTED)
        ):
            rclpy.spin_once(self.move_arm_named_client)
    
    def pick_or_place(self, pos_list, pick=True):
        self.logger.info(f"Pick: {pick}")
        self.logger.info(f"Position: {pos_list}")
        
        self.pick_or_place_client.send_goal(pos_list, pick)
        while (
            (self.pick_or_place_client.status != GoalStatus.STATUS_SUCCEEDED) and
            (self.pick_or_place_client.status != GoalStatus.STATUS_ABORTED)
        ):
            rclpy.spin_once(self.pick_or_place_client)
    
    def move_to_goal(self, goal):
        self.move_base_client.send_goal(*goal)
        while self.move_base_client.status != GoalStatus.STATUS_SUCCEEDED:
            rclpy.spin_once(self.move_base_client)
            rclpy.spin_once(self)
        rclpy.spin_until_future_complete(self, Future(), timeout_sec=0.5)

    def store_center_box_data(self):
        corners_of_box = [
            [self.center_tr_pose.pose.position.x, self.center_tr_pose.pose.position.y],
            [self.center_tl_pose.pose.position.x, self.center_tl_pose.pose.position.y],
            [self.center_br_pose.pose.position.x, self.center_br_pose.pose.position.y],
            [self.center_bl_pose.pose.position.x, self.center_bl_pose.pose.position.y]
        ]
        
        center_of_box = [np.mean([corner[0] for corner in corners_of_box]),
                            np.mean([corner[1] for corner in corners_of_box])]
        
        self.logger.info(f"Center of box: {center_of_box}")
        
        # Distance to each corner
        distances = [np.sqrt((corner[0] - self.current_pose.pose.pose.position.x)**2 + 
                             (corner[1] - self.current_pose.pose.pose.position.y)**2) 
                             for corner in corners_of_box]
        
        # Find the closest corner
        closest_corner = np.argmin(distances)
        self.logger.info(f"Closest corner: {closest_corner}")
        
        if closest_corner == 0 or closest_corner == 2: # right side
            closest_corners = [0, 2]
        else: # left side
            closest_corners = [1, 3]
        self.corners_of_box = corners_of_box
        self.center_of_box = center_of_box
        self.closest_corners = closest_corners

    def move_next_to_center_box(self, margin, perp_margin=0.0):
        # Find the midpoint of the two closest corners
        x_mid = (self.corners_of_box[self.closest_corners[0]][0] + self.corners_of_box[self.closest_corners[1]][0]) / 2
        y_mid = (self.corners_of_box[self.closest_corners[0]][1] + self.corners_of_box[self.closest_corners[1]][1]) / 2
        self.logger.info(f"Midpoint: {x_mid}, {y_mid}")
        
        # Anlge from the midpoint to the center of the box
        angle = np.arctan2(self.center_of_box[1] - y_mid, self.center_of_box[0] - x_mid)
        self.logger.info(f"Angle: {angle}")
        
        # Vector from the midpoint to the center of the box
        vector = np.array([self.center_of_box[0] - x_mid, self.center_of_box[1] - y_mid])
        vector = vector / np.linalg.norm(vector)
        self.logger.info(f"Vector: {vector}")
        
        # Vector perpendicular to the vector from the midpoint to the center of the box
        perp_vector = np.array([-vector[1], vector[0]])
        
        offset = margin * vector + perp_margin * perp_vector
        
        # Desired position is the midpoint plus a margin in the opposite 
        # direction of the center of the box
        desired_position = [x_mid - offset[0], y_mid - offset[1]]
        
        self.logger.info(f"Moving to {desired_position}")
        
        self.move_to_goal([desired_position[0], desired_position[1], angle, True, False])
        
        # Sleep for a bit to let the robot settle and update frames
        rclpy.spin_until_future_complete(self, Future(), timeout_sec=1.0)
        
        # Move arm out of way of camera
        self.move_arm_named_pose('Sleep')
        
        curr_pos = [self.current_pose.pose.pose.position.x, self.current_pose.pose.pose.position.y]
        
        horizontal_distance = np.sqrt((self.center_of_box[0] - curr_pos[0])**2 +
                                        (self.center_of_box[1] - curr_pos[1])**2)
        
        # Calculate angle from camera locobot link frame to the center of the box
        angle = np.arctan2(0.5797, horizontal_distance)
        
        # Tilt camera down to look at the center of the box
        self.logger.info(f"Looking at the center of the box with angle {angle}")
        self.move_camera(0.0, angle)

    def move_camera(self, pan, tilt):
        # Positive tilt is down
        # Positive pan is left
        msg = Float64MultiArray()
        msg.data = [pan, tilt]
        self.mobile_camera_publisher.publish(msg)
        rclpy.spin_until_future_complete(self, Future(), timeout_sec=2.5)

    def find_april_tags(self, 
            list_of_poses=[[0.0, 0.0, 0.0], [0.0, 0.0, 2.09], [0.0, 0.0, 4.19]]):
        # Attempt to find the april tags.
        # We will accomplish this by first panning the camera, then we will rotate the base
        # and move the camera again.
        
        self.move_arm_named_pose('Sleep')
        
        #! Use for test only!
        # self.set_april_poses()

        # Move the base and then lookaround again
        for pose_i in list_of_poses:
            goal = [pose_i[0], pose_i[1], pose_i[2], False, True]
            self.move_to_goal(goal)
            rclpy.spin_until_future_complete(self, Future(), timeout_sec=1.0)
            self.move_camera(0.0, 0.35) # down ~20 deg, straight ahead
            rclpy.spin_until_future_complete(self, Future(), timeout_sec=1.0)
            self.move_camera(0.5, 0.35) # down ~20 deg, left ~30 degrees
            rclpy.spin_until_future_complete(self, Future(), timeout_sec=1.0)
            self.move_camera(-0.5, 0.35) # down ~20 deg, right ~30 degrees
            rclpy.spin_until_future_complete(self, Future(), timeout_sec=1.0)
            self.move_camera(0.5, 0.75) # down ~20 deg, left ~60 degrees
            rclpy.spin_until_future_complete(self, Future(), timeout_sec=1.0)
            self.move_camera(-0.5, 0.75) # down ~20 deg, right ~60 degrees
            rclpy.spin_until_future_complete(self, Future(), timeout_sec=1.0)
            self.move_camera(0.0, 0.0) # Straight ahead
            rclpy.spin_until_future_complete(self, Future(), timeout_sec=1.0)
        
        # Rotate the base back to straight
        goal = [0.0, 0.0, 0.0, False, True]
        self.move_to_goal(goal)
        rclpy.spin_until_future_complete(self, Future(), timeout_sec=3.0)
        
        # Verify we found the list of positions
        all_tags_found = True
        for position in LIST_OF_POSITIONS:
            if getattr(self, f'{position}_pose') is None:
                self.logger.warn(f"Did not find {position}")
                all_tags_found = False
        
        if all_tags_found:
            self.destroy_april_tag_subscriptions()
            self.logger.info("All tags found!")
        else:
            self.logger.info("Not all tags found")


    def world_to_locobot_frame(self, pos_in_world):
        rclpy.spin_once(self, timeout_sec=0.1)
        curr_pose = self.current_pose
        q = [curr_pose.pose.pose.orientation.x,
                curr_pose.pose.pose.orientation.y,
                curr_pose.pose.pose.orientation.z,
                curr_pose.pose.pose.orientation.w]
        euler = tf_transformations.euler_from_quaternion(q)
        ang = -euler[2]
        rot_mat = np.array([[np.cos(ang), -np.sin(ang)],
                            [np.sin(ang), np.cos(ang)]])
        
        xp = pos_in_world[0] - curr_pose.pose.pose.position.x
        yp = pos_in_world[1] - curr_pose.pose.pose.position.y
        pos_in_locobot = rot_mat @ np.array([xp, yp])
        return pos_in_locobot
    
    def calcualte_pos_yaw_from_tag_pose(self, tag_pose, offset_x, offset_y):
        quaternion = (
            tag_pose.pose.orientation.x,
            tag_pose.pose.orientation.y,
            tag_pose.pose.orientation.z,
            tag_pose.pose.orientation.w
        )
        euler = tf_transformations.euler_from_quaternion(quaternion)
        rot_mat = np.array([[np.cos(euler[2]), -np.sin(euler[2])],
                            [np.sin(euler[2]), np.cos(euler[2])]])
        
        direction_vector =  rot_mat @ np.array([offset_x, offset_y])
        target_position = np.array([tag_pose.pose.position.x, tag_pose.pose.position.y]) + direction_vector
        
        # Yaw is rotation + 90 degrees, modulo 2pi
        yaw = (euler[2] + np.pi/2) % (2 * np.pi)
        
        return target_position, yaw


    def destroy_april_tag_subscriptions(self):
        self.logger.info("Destroying april tag pose subscriptions")
        self.destroy_subscription(self.center_tr_pose)
        self.destroy_subscription(self.center_tl_pose)
        self.destroy_subscription(self.center_br_pose)
        self.destroy_subscription(self.center_bl_pose)
        self.destroy_subscription(self.a_build_a_pose)
        self.destroy_subscription(self.a_build_b_pose)
        self.destroy_subscription(self.b_build_a_pose)
        self.destroy_subscription(self.b_build_b_pose)

    def place_block_at_location(self, pos_in_world):
        self.logger.info(f"Desired place in world frame: {pos_in_world}")
        
        pose_in_world = PoseStamped()
        pose_in_world.header.frame_id = 'world'
        pose_in_world.header.stamp = self.get_clock().now().to_msg()
        pose_in_world.pose.position.x = pos_in_world[0]
        pose_in_world.pose.position.y = pos_in_world[1]
        pose_in_world.pose.position.z = 0.0
        pose_in_world.pose.orientation.x = 0.0
        pose_in_world.pose.orientation.y = 0.0
        pose_in_world.pose.orientation.z = 0.0
        pose_in_world.pose.orientation.w = 1.0
        
        rclpy.spin_until_future_complete(self, Future(), timeout_sec=0.5)
        
        pos_in_locobot_frame2 = self.world_to_locobot_frame(pos_in_world)
        self.logger.info(f"**Position in locobot/base_link frame: {pos_in_locobot_frame2}")
        
        now = self.get_clock().now().to_msg()
        self.logger.info(f"Waiting for transform to be available. Req time: {now}")
        still_looking = True
        while still_looking:
            # Check if the transform is available
            if self.tf_buffer.can_transform('locobot/base_link', 'world', now):
                still_looking = False
            rclpy.spin_once(self, timeout_sec=0.1) 
            
        # Create a transform form using the current_pose pose
        
        
        
        transform = self.tf_buffer.lookup_transform('locobot/base_link', 'world', now)
        
        self.logger.info(f"Time: {transform.header.stamp}")
        self.logger.info(f"Transform: {transform.transform}")
        self.logger.info(f'Current Pose Stamp: {self.current_pose.header.stamp}')
        self.logger.info(f"Current Pose Frame ID: {self.current_pose.header.frame_id}")
        self.logger.info(f"Current Pose: {self.current_pose.pose.pose}")
        
        pose_in_locobot_frame = tf2_geometry_msgs.do_transform_pose(pose_in_world.pose, transform)
    
        pos_in_locobot_frame = [pose_in_locobot_frame.position.x,
                                pose_in_locobot_frame.position.y,
                                0.0]
        
    
        self.logger.info(f"Position in locobot/base_link frame: {pos_in_locobot_frame}")
        self.pick_or_place([pos_in_locobot_frame[0], pos_in_locobot_frame[1], 0.0], False)
    
    def find_closest_cube(self):
        now = self.get_clock().now().to_msg()
        rclpy.spin_until_future_complete(self, Future(), timeout_sec=0.1)
        transform = self.tf_buffer.lookup_transform('world', 'locobot/gripper_link', now)
        
        # self.logger.info(f"Gripper_link_tf:  {transform}")
        
        robot_x = transform.transform.translation.x
        robot_y = transform.transform.translation.y
        
        min_distance = 100000
        min_cube_name = None
        for model_name, pose in self.model_states.items():
            # self.logger.info(f"Model: {model_name}")
            if 'cube' in model_name:
                cube_x = pose.position.x
                cube_y = pose.position.y
                
                distance = np.sqrt((robot_x - cube_x)**2 + (robot_y - cube_y)**2)
                # self.logger.info(f"Distance to {model_name}: {distance}")
                if distance < min_distance:
                    min_distance = distance
                    min_cube_name = model_name
        self.logger.info(f"Closest cube: {min_cube_name}")
        self.logger.info(f"Distance: {min_distance}")
        return min_cube_name
    
    def construct_pattern(self, block_pattern, construction_tag, perp_margin=0.0):
        for block in block_pattern:
            block_color = block['color']
            self.logger.info(f"Moving next to the center box to find the closest {block_color} block")
        
            self.move_next_to_center_box(0.25, perp_margin)
            
            rclpy.spin_until_future_complete(self, Future(), timeout_sec=2.5)
            now = self.get_clock().now().to_msg()
            rclpy.spin_until_future_complete(self, Future(), timeout_sec=0.2)
            
            self.block_pos = self.perception_client.closest_blocks(block_color, self.tf_buffer, now)
            
            self.logger.info(f"Closest {block_color} block: {self.block_pos}")
            
            pos_in_base_link = [self.block_pos[0], self.block_pos[1], 0.03]
            self.logger.info(f"Moving arm to locobot/base_link frame position: {pos_in_base_link}")
            
            self.pick_or_place(pos_in_base_link, True)
            
            rclpy.spin_until_future_complete(self, Future(), timeout_sec=1.0)
            
            cube_name = self.find_closest_cube()
            
            self.attach_client.send_request(cube_name)
            self.move_arm_named_pose('Sleep')
            
            desired_relative_position = [block['position']['x'], block['position']['y']]
            self.logger.info(f"Desired relative position: {desired_relative_position}")
            
            rclpy.spin_until_future_complete(self, Future(), timeout_sec=1.0)
            
            build_pose = getattr(self, f'{construction_tag}_pose')
            self.logger.info(f"Own build pose: {build_pose}")
            
            pos, yaw = self.calcualte_pos_yaw_from_tag_pose(build_pose, 0.0, -0.25)
            
            goal = [pos[0], pos[1], yaw, True, False]
            self.logger.info(f"Moving to goal: {goal}")
            self.move_to_goal(goal)
            
            rclpy.spin_until_future_complete(self, Future(), timeout_sec=1.0)
            
            self.logger.info(f"Current Pose: {self.current_pose}")
            
            pos, _ = self.calcualte_pos_yaw_from_tag_pose(
                build_pose, 
                desired_relative_position[0] + PATTERN_OFFSET_X, 
                desired_relative_position[1] + PATTERN_OFFSET_Y
            )
            
            self.place_block_at_location(pos)
            
            self.detach_client.send_request(cube_name)
            self.move_arm_named_pose('Sleep')   
            rclpy.spin_until_future_complete(self, Future(), timeout_sec=1.0)
    
    def move_to_view_opp_pattern(self):
        # We want to get to the boundary of the "do not cross" area looking at the 
        # other teams pattern.
        other_pattern_x = getattr(self, f'{OPP_BUILD}_pose').pose.position.x
        other_pattern_y = getattr(self, f'{OPP_BUILD}_pose').pose.position.y
        
        own_opp_build_x = getattr(self, f'{OWN_BUILD_OPP}_pose').pose.position.x
        own_opp_build_y = getattr(self, f'{OWN_BUILD_OPP}_pose').pose.position.y
        
        # Vector defined from own_opp_build to other_pattern
        vector_a = [other_pattern_x - own_opp_build_x, other_pattern_y - own_opp_build_y]
        vector_a = vector_a / np.linalg.norm(vector_a)
        
        # Vector defining "do not cross"
        vb_x = self.corners_of_box[self.closest_corners[0]][0] - self.corners_of_box[self.closest_corners[1]][0]
        vb_y = self.corners_of_box[self.closest_corners[0]][1] - self.corners_of_box[self.closest_corners[1]][1]
        vector_b = [vb_x, vb_y]
        vector_b = vector_b / np.linalg.norm(vector_b)
        
        intersect_a_b_x, intersect_a_b_y = find_intersection(
            other_pattern_x, other_pattern_y,
            own_opp_build_x, own_opp_build_y,
            self.corners_of_box[self.closest_corners[0]][0], self.corners_of_box[self.closest_corners[0]][1],
            self.corners_of_box[self.closest_corners[1]][0], self.corners_of_box[self.closest_corners[1]][1]
        )
        
        # Move to the intersection point but at an offset along -vector_a
        offset = 0.25
        angle = np.arctan2(vector_a[1], vector_a[0])
        goal = [intersect_a_b_x - offset * vector_a[0], intersect_a_b_y - offset * vector_a[1], angle, True, False]
        self.logger.info(f"Moving to view the other teams pattern: {goal}")
        self.move_to_goal(goal)
        rclpy.spin_until_future_complete(self, Future(), timeout_sec=1.0)
        
        # Tilt camera down if needed to view the other teams pattern
        d = np.sqrt((other_pattern_x - self.current_pose.pose.pose.position.x)**2 +
                    (other_pattern_y - self.current_pose.pose.pose.position.y)**2)
        angle = np.arctan2(0.5797, d)
        self.move_camera(0.0, angle)
    
    def determine_opp_pattern(self):
        rclpy.spin_until_future_complete(self, Future(), timeout_sec=1.0)
        now = self.get_clock().now().to_msg()
        rclpy.spin_until_future_complete(self, Future(), timeout_sec=0.2)
        red_blocks, blue_blocks, green_blocks, yellow_blocks = self.perception_client.all_blocks_world(self.tf_buffer, now)
        
        tag_pose = getattr(self, f'{OPP_BUILD}_pose').pose
        
        # Find the relative pose of the blocks with respect to the other teams build tag
        opp_build_x = tag_pose.position.x
        opp_build_y = tag_pose.position.y
        
        quaternion = (
            tag_pose.orientation.x,
            tag_pose.orientation.y,
            tag_pose.orientation.z,
            tag_pose.orientation.w
        )
        euler = tf_transformations.euler_from_quaternion(quaternion)
        rot_mat = np.array([[np.cos(euler[2]), -np.sin(euler[2])],
                            [np.sin(euler[2]), np.cos(euler[2])]])
        
        blocks = [red_blocks, blue_blocks, green_blocks, yellow_blocks]
        block_colors = ['red', 'blue', 'green', 'yellow']
        pattern = []
        num_blocks = 0
        for color, blocks in zip(block_colors, blocks):
            for block in blocks: 
                block_info = dict()
                num_blocks = num_blocks + 1
                block_info['block_id'] = num_blocks
                block_info['color'] = color
                block_info['position'] = dict()
                
                direction_vector = np.array([block[0] - opp_build_x, block[1] - opp_build_y])
                offsets = rot_mat.T @ direction_vector
            
                block_info['position']['x'] = offsets[0] - PATTERN_OFFSET_X
                block_info['position']['y'] = offsets[1] - PATTERN_OFFSET_Y
                pattern.append(block_info)
                self.logger.info(f"Opp Block Offset: {block_info}")
        return pattern
            
    
    def main_logic(self):
        self.main_logic_done_event = Future()
        
        # Find the april tags so ww know where our important locations are
        self.find_april_tags()
        
        # Calcualte and store center box data
        self.store_center_box_data()
        
        # Construct our own pattern first
        self.construct_pattern(self.block_pattern, OWN_BUILD)
        
        # After contructing our own pattern, we need to observe the other teams pattern
        # To get a better view, we will move to the edge of the "do not cross" boundary
        # defined by the apriltags.
        
        # To help with conflict, let's first navigate back to the middle (where we started)
        goal = [0.0, 0.0, 0.0, False, False]
        self.move_to_goal(goal)
        rclpy.spin_until_future_complete(self, Future(), timeout_sec=1.0)
        
        # Move to viewing position
        self.move_to_view_opp_pattern()
        rclpy.spin_until_future_complete(self, Future(), timeout_sec=1.0)
        
        # Determine teammates pattern (assuming complete)
        opp_pattern = self.determine_opp_pattern()
        rclpy.spin_until_future_complete(self, Future(), timeout_sec=1.0)
        
        # Go back to start for collision avoidance reasons
        goal = [0.0, 0.0, 0.0, False, False]
        self.move_to_goal(goal)
        rclpy.spin_until_future_complete(self, Future(), timeout_sec=1.0)
        
        # Build the other teams pattern
        self.construct_pattern(opp_pattern, OWN_BUILD_OPP, perp_margin=0.25)
        
        # Go back to start for collision avoidance reasons
        goal = [0.0, 0.0, 0.0, True, False]
        self.move_to_goal(goal)
        rclpy.spin_until_future_complete(self, Future(), timeout_sec=1.0)
        
        self.main_logic_done_event.set_result(True)  
               

def main(args=None):
    rclpy.init(args=args)
    state_machine = StateMachine()
    
    state_machine.set_parameters([Parameter('use_sim_time', Parameter.Type.BOOL, True)])
    
    executor = MultiThreadedExecutor(num_threads=4)
    executor.add_node(state_machine)
    
    main_thread = threading.Thread(target=state_machine.main_logic)
    main_thread.start()
    
    executor.spin_until_future_complete(state_machine.main_logic_done_event)
    main_thread.join()
    
    executor.shutdown()
    state_machine.destroy_node()
    rclpy.shutdown()
        
        
def quaternion_to_yaw(quaternion):
    """
    Convert a quaternion to yaw.

    Parameters:
    - quaternion: A tuple of (x, y, z, w) representing the quaternion.

    Returns:
    - yaw: The yaw angle in radians.
    """
    euler = tf_transformations.euler_from_quaternion(quaternion)
    yaw = euler[2]  # Yaw is the rotation around Z-axis
    return yaw  

def find_intersection(x1, y1, x2, y2, x3, y3, x4, y4):
    denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4)
    if denominator == 0:
        return None  # Lines are parallel
    
    x_numerator = (x1*y2 - y1*x2)*(x3 - x4) - (x1 - x2)*(x3*y4 - y3*x4)
    y_numerator = (x1*y2 - y1*x2)*(y3 - y4) - (y1 - y2)*(x3*y4 - y3*x4)
    
    x = x_numerator / denominator
    y = y_numerator / denominator
    
    return x, y

if __name__ == '__main__':
    main()