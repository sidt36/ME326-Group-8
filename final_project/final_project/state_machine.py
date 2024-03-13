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
from geometry_msgs.msg import Pose
from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.parameter import Parameter

import numpy as np
import tf2_ros
import tf2_geometry_msgs
from tf2_ros import Buffer, TransformListener
from std_msgs.msg import Float64MultiArray
from nav_msgs.msg import Odometry
from rclpy.qos import qos_profile_sensor_data

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
        
        # self.create_subscription(PoseStamped, '/center_tr', self.center_tr_callback, 10)
        # self.create_subscription(PoseStamped, '/center_tl', self.center_tl_callback, 10)
        # self.create_subscription(PoseStamped, '/center_br', self.center_br_callback, 10)
        # self.create_subscription(PoseStamped, '/center_bl', self.center_bl_callback, 10)
        # self.create_subscription(PoseStamped, '/a_build_a', self.a_build_a_callback, 10)
        # self.create_subscription(PoseStamped, '/a_build_b', self.a_build_b_callback, 10)
        # self.create_subscription(PoseStamped, '/b_build_a', self.b_build_a_callback, 10)
        # self.create_subscription(PoseStamped, '/b_build_b', self.b_build_b_callback, 10)
        
        self.find_april_tag_done_event = Future()
        self.move_next_to_center_box_done_event = Future()
        self.move_to_goal_done_event = Future()
        self.move_arm_done_event = Future()
        self.place_block_done_event = Future()
        self.perception_done_event = Future()
        self.current_pose_done_event = Future()
        self.main_logic_done_event = None
        
        self.create_subscription(POSE_MSG_TYPE, POSE_MSG, self.pose_callback, qos_profile_sensor_data)
        self.tf_buffer = Buffer(cache_time=rclpy.duration.Duration(seconds=5))
        self.tf_listener = TransformListener(self.tf_buffer, self, qos=50)

    def pose_callback(self, msg):
        self.logger.info(f"Received pose message: {msg.header.stamp}")
        self.current_pose = msg
        self.current_pose_done_event.set_result(True)
    
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
        self.move_arm_done_event = Future()
        self.move_arm_named_client.send_goal(pose_name)
        while (
            (self.move_arm_named_client.status != GoalStatus.STATUS_SUCCEEDED) and
            (self.move_arm_named_client.status != GoalStatus.STATUS_ABORTED)
        ):
            rclpy.spin_once(self.move_arm_named_client)
        self.move_arm_done_event.set_result(True)
    
    def pick_or_place(self, pos_list, pick=True):
        self.move_arm_done_event = Future()
        self.logger.info(f"Pick: {pick}")
        self.logger.info(f"Position: {pos_list}")
        
        self.pick_or_place_client.send_goal(pos_list, pick)
        while (
            (self.pick_or_place_client.status != GoalStatus.STATUS_SUCCEEDED) and
            (self.pick_or_place_client.status != GoalStatus.STATUS_ABORTED)
        ):
            rclpy.spin_once(self.pick_or_place_client)
        self.move_arm_done_event.set_result(True)
    
    def move_to_goal(self, goal):
        self.move_to_goal_done_event = Future()
        self.move_base_client.send_goal(*goal)
        while self.move_base_client.status != GoalStatus.STATUS_SUCCEEDED:
            rclpy.spin_once(self.move_base_client)
            rclpy.spin_once(self)
        time.sleep(1.0)
        self.move_to_goal_done_event.set_result(True)

    def move_next_to_center_box(self, margin):
        self.move_next_to_center_box_done_event = Future()
        # First let's calculate the edge of the box closest to us
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
        
        # Find the midpoint of the two closest corners
        x_mid = (corners_of_box[closest_corners[0]][0] + corners_of_box[closest_corners[1]][0]) / 2
        y_mid = (corners_of_box[closest_corners[0]][1] + corners_of_box[closest_corners[1]][1]) / 2
        self.logger.info(f"Midpoint: {x_mid}, {y_mid}")
        
        # Anlge from the midpoint to the center of the box
        angle = np.arctan2(center_of_box[1] - y_mid, center_of_box[0] - x_mid)
        self.logger.info(f"Angle: {angle}")
        
        # Vector from the midpoint to the center of the box
        vector = [center_of_box[0] - x_mid, center_of_box[1] - y_mid]
        vector = vector / np.linalg.norm(vector)
        self.logger.info(f"Vector: {vector}")
        
        # Desired position is the midpoint plus a margin in the opposite 
        # direction of the center of the box
        desired_position = [x_mid - margin * vector[0], y_mid - margin * vector[1]]
        
        self.logger.info(f"Moving to {desired_position}")
        
        self.move_to_goal([desired_position[0], desired_position[1], angle, True, False])
        
        # Sleep for a bit to let the robot settle and update frames
        time.sleep(2.0)
        
        # Move arm out of way of camera
        self.move_arm_named_pose('Sleep')
        
        curr_pos = [self.current_pose.pose.pose.position.x, self.current_pose.pose.pose.position.y]
        
        horizontal_distance = np.sqrt((center_of_box[0] - curr_pos[0])**2 +
                                        (center_of_box[1] - curr_pos[1])**2)
        
        # Calculate angle from camera locobot link frame to the center of the box
        angle = np.arctan2(0.5797, horizontal_distance)
        
        # Tilt camera down to look at the center of the box
        self.logger.info(f"Looking at the center of the box with angle {angle}")
        self.move_camera(0.0, angle)
        
        self.move_next_to_center_box_done_event.set_result(True)

    def move_camera(self, pan, tilt):
        # Positive tilt is down
        # Positive pan is left
        msg = Float64MultiArray()
        msg.data = [pan, tilt]
        self.mobile_camera_publisher.publish(msg)
        time.sleep(2.0)
        rclpy.spin_once(self)

    def find_april_tags(self, list_of_poses=[[-1.0, 0.0, 0.0]]):
        # Attempt to find the april tags.
        # We will accomplish this by first panning the camera, then we will rotate the base
        # and move the camera again.
        
        self.move_arm_named_pose('Sleep')
        
        #! Sim use only!
        self.set_april_poses()
        
        # self.move_camera(0.0, 0.35) # down ~20 deg, straight ahead
        # self.move_camera(0.5, 0.35) # down ~20 deg, left ~30 degrees
        # self.move_camera(-0.5, 0.35) # down ~20 deg, right ~30 degrees
        # # self.move_camera(1.4, 0.35) # down ~20 deg, left ~80 degrees
        # # self.move_camera(-1.4, 0.35) # down ~20 deg, right ~80 degrees
        # self.move_camera(0.0, 0.0) # Straight ahead
        
        # # Move the base and then lookaround again
        # for pose_i in list_of_poses:
        #     goal = [pose_i[0], pose_i[1], pose_i[2], True, False]
        #     self.move_to_goal(goal)
            
        #     self.move_camera(0.0, 0.35) # down ~20 deg, straight ahead
        #     self.move_camera(0.5, 0.35) # down ~20 deg, left ~30 degrees
        #     self.move_camera(-0.5, 0.35) # down ~20 deg, right ~30 degrees
        #     # self.move_camera(1.4, 0.35) # down ~20 deg, left ~80 degrees
        #     # self.move_camera(-1.4, 0.35) # down ~20 deg, right ~80 degrees
        #     self.move_camera(0.0, 0.0) # Straight ahead
        
        # # Rotate the base 180 degrees (yaw to 0)
        # goal = [0.0, 0.0, 0.0, True, False]
        # self.move_to_goal(goal)

        
        # Verify we found the list of positions
        all_tags_found = True
        for position in LIST_OF_POSITIONS:
            if getattr(self, f'{position}_pose') is None:
                self.logger.warn(f"Did not find {position}")
                all_tags_found = False
        self.find_april_tag_done_event.set_result(all_tags_found)

    # def use_perception_closest_block(self, desired_block_color):
    #     # Use the perception service to find the closest block of the desired color
    #     self.perception_done_event = Future()
    #     self.logger.info(f"Using perception to find the closest {desired_block_color} block")
    #     closest_red, closest_blue, closest_green, closest_yellow = self.perception_client.closest_blocks('/locobot/base_link', 0, 0)
        
    #     desired_block_pos = None
    #     if desired_block_color == 'red':
    #         desired_block_pos = closest_red
    #     elif desired_block_color == 'blue':
    #         desired_block_pos = closest_blue
    #     elif desired_block_color == 'green':
    #         desired_block_pos = closest_green
    #     elif desired_block_color == 'yellow':
    #         desired_block_pos = closest_yellow
    #     else:
    #         self.logger.warn(f"Invalid color: {desired_block_color}")

    #     if desired_block_pos is None:
    #             self.logger.warn(f"No {desired_block_color} blocks found")
        
    #     self.logger.info(f"Closest {desired_block_color} block: {desired_block_pos}")
        
    #     self.block_pos = desired_block_pos
    #     self.perception_done_event.set_result(True)

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
        self.place_block_done_event = Future()
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
        
        self.place_block_done_event.set_result(True)
        
    def main_logic(self):
        self.main_logic_done_event = Future()
        
        self.find_april_tags()
        
        for block in self.block_pattern:
            block_color = block['color']
            self.logger.info(f"Moving next to the center box to find the closest {block_color} block")
        
            self.move_next_to_center_box(0.35)
            
            
            rclpy.spin_until_future_complete(self, Future(), timeout_sec=1.0)
            now = self.get_clock().now().to_msg()
            rclpy.spin_until_future_complete(self, Future(), timeout_sec=0.2)
            
            self.perception_client.closest_blocks(block_color, self.tf_buffer, now)
            self.block_pos = self.perception_client.block_pos
            
            self.logger.info(f"Closest {block_color} block: {self.block_pos}")
            
            pos_in_base_link = [self.block_pos[0], self.block_pos[1], 0.03]
            self.logger.info(f"Moving arm to locobot/base_link frame position: {pos_in_base_link}")
            
            self.pick_or_place(pos_in_base_link, True)
            
            rclpy.spin_until_future_complete(self, Future(), timeout_sec=1.0)
            
            cube_name = block['name']
            self.attach_client.send_request(cube_name)
            self.move_arm_named_pose('Sleep')
            
            desired_relative_position = [block['position']['x'], block['position']['y']]
            self.logger.info(f"Desired relative position: {desired_relative_position}")
            
            rclpy.spin_until_future_complete(self, Future(), timeout_sec=1.0)
            
            build_pose = getattr(self, f'{OWN_BUILD}_pose')
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
            
            self.detach_client.send_request(block['name'])
            self.move_arm_named_pose('Sleep')   
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

    # Run find_april_tags in a separate thread
    # april_thread = threading.Thread(target=state_machine.find_april_tags)
    # april_thread.start()

    # executor.spin_until_future_complete(state_machine.find_april_tag_done_event)

    # Wait for the april_tag_thread to finish
    # april_thread.join()
    # if state_machine.find_april_tag_done_event.result():
        # state_machine.logger.info("All tags found!")
        # We now don't need the subscriptions to the april tag locations
        # state_machine.destroy_april_tag_subscriptions()
    # else:
        # state_machine.logger.warn("Not all tags found")
        
    # We need to repeat this process x times, where x is the number of objects we need
    # to pick up and place.
    # for block in state_machine.block_pattern:
    #     # Move next to the center box
    #     block_color = block['color']
    #     state_machine.logger.info(f"Moving next to the center box to find the closest {block_color} block")
    
    #     move_near_center_box_thread = threading.Thread(target=state_machine.move_next_to_center_box, args=(0.35,))
    #     move_near_center_box_thread.start()
        
    #     executor.spin_until_future_complete(state_machine.move_next_to_center_box_done_event)
    #     move_near_center_box_thread.join()
        
    #     executor.spin_until_future_complete(Future(), timeout_sec=2.0)
        
    #     #TODO 
    #     # Use the percpetion service to find the object of interest
    #     percep_thread = threading.Thread(target=preception_client.closest_blocks, args=(block_color,))
    #     percep_thread.start()
        
    #     executor.spin_until_future_complete(preception_client.done_event)
    #     percep_thread.join()
        
    #     state_machine.logger.info(f"Closest {block_color} block: {preception_client.block_pos}")
    #     state_machine.block_pos = preception_client.block_pos
        
    #     # use_perception_thread = threading.Thread(target=state_machine.use_perception_closest_block, args=(block_color,))
    #     # use_perception_thread.start()
        
    #     # executor.spin_until_future_complete(state_machine.perception_done_event)
    #     # use_perception_thread.join()
        
    #     # Use the arm to pickup the object of interest
    #     pos_in_base_link = [state_machine.block_pos[0], state_machine.block_pos[1], 0.03]
        
    #     state_machine.logger.info(f"Moving arm to locobot/base_link frame position: {pos_in_base_link}")
        
    #     pick_place_thread = threading.Thread(target=state_machine.pick_or_place, args=(pos_in_base_link, True))
    #     pick_place_thread.start()
        
    #     executor.spin_until_future_complete(state_machine.move_arm_done_event)
    #     pick_place_thread.join()
        
    #     #TODO
    #     # Attach the block to the gripper to simulate the grasp
    #     #! Update to be function baed on write_location
    #     cube_name = block['name']
    #     state_machine.attach_client.send_request(cube_name)
    #     state_machine.move_arm_named_pose('Sleep')
        
    #     #TODO
    #     # Move the robot to the dropoff location
    #     desired_relative_position = [block['position']['x'], block['position']['y']]
    #     state_machine.logger.info(f"Desired relative position: {desired_relative_position}")
        
    #     executor.spin_until_future_complete(Future(), timeout_sec=2.0)
        
    #     build_pose = getattr(state_machine, f'{OWN_BUILD}_pose')
    #     state_machine.logger.info(f"Own build pose: {build_pose}")
        
    #     executor.spin_until_future_complete(Future(), timeout_sec=2.0)
    #     pos, yaw = state_machine.calcualte_pos_yaw_from_tag_pose(build_pose, 0.0, -0.25)
        
    #     goal = [pos[0], pos[1], yaw, True, False]
    #     state_machine.logger.info(f"Moving to goal: {goal}")
    #     move_to_goal_thread = threading.Thread(target=state_machine.move_to_goal, args=(goal,))
    #     move_to_goal_thread.start()
    #     executor.spin_until_future_complete(state_machine.move_to_goal_done_event)
    #     move_to_goal_thread.join()
        
    #     state_machine.logger.info(f"Rejoined after moving to goal")
    #     state_machine.logger.info(f"Current Pose: {state_machine.current_pose}")
        
    #     # TODO
    #     # Use the arm to dropoff the object of interest at the designated dropoff location
    #     pos, _ = state_machine.calcualte_pos_yaw_from_tag_pose(
    #         build_pose, 
    #         desired_relative_position[0] + PATTERN_OFFSET_X, 
    #         desired_relative_position[1] + PATTERN_OFFSET_Y
    #     )
        
    #     place_thread = threading.Thread(target=state_machine.place_block_at_location, args=(pos,))
    #     place_thread.start()
    #     executor.spin_until_future_complete(state_machine.place_block_done_event)
    #     place_thread.join()
        
    #     state_machine.detach_client.send_request(cube_name)
    #     state_machine.move_arm_named_pose('Sleep')
    
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

if __name__ == '__main__':
    main()