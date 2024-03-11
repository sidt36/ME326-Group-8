#!/usr/bin/env python3
import time
import rclpy
import threading
from rclpy.executors import Future
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import ReentrantCallbackGroup

import numpy as np
from tf2_ros import Buffer, TransformListener
from std_msgs.msg import Float64MultiArray
from nav_msgs.msg import Odometry
from rclpy.qos import qos_profile_sensor_data

from action_msgs.msg import GoalStatus
from action_client.move_base_client import MoveActionClient

POSE_MSG = '/locobot/sim_ground_truth_pose'
POSE_MSG_TYPE = Odometry

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
        
        self.mobile_camera_publisher = self.create_publisher(Float64MultiArray, CAM_CMD_MSG, 1)
        
        self.create_subscription(PoseStamped, '/center_tr', self.center_tr_callback, 10)
        self.create_subscription(PoseStamped, '/center_tl', self.center_tl_callback, 10)
        self.create_subscription(PoseStamped, '/center_br', self.center_br_callback, 10)
        self.create_subscription(PoseStamped, '/center_bl', self.center_bl_callback, 10)
        self.create_subscription(PoseStamped, '/a_build_a', self.a_build_a_callback, 10)
        self.create_subscription(PoseStamped, '/a_build_b', self.a_build_b_callback, 10)
        self.create_subscription(PoseStamped, '/b_build_a', self.b_build_a_callback, 10)
        self.create_subscription(PoseStamped, '/b_build_b', self.b_build_b_callback, 10)
        
        self.find_april_tag_done_event = Future()
        self.move_next_to_center_box_done_event = Future()
        self.move_to_goal_done_event = Future()
        
        self.create_subscription(POSE_MSG_TYPE, POSE_MSG, self.pose_callback, qos_profile_sensor_data)
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

    def pose_callback(self, msg):
        self.current_pose = msg
    
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
    
    def move_to_goal(self, goal):
        self.move_to_goal_done_event = Future()
        self.move_base_client.send_goal(*goal)
        while self.move_base_client.status != GoalStatus.STATUS_SUCCEEDED:
            rclpy.spin_once(self.move_base_client)
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
        self.get_logger().info(f"Center of box: {center_of_box}")
        
        # Distance to each corner
        distances = [np.sqrt((corner[0] - self.current_pose.pose.pose.position.x)**2 + 
                             (corner[1] - self.current_pose.pose.pose.position.y)**2) 
                             for corner in corners_of_box]
        
        # Find the two closest corners
        closest_corners = np.argsort(distances)[:2]
        self.get_logger().info(f"Closest corners: {closest_corners}")
        
        # Find the midpoint of the two closest corners
        x_mid = (corners_of_box[closest_corners[0]][0] + corners_of_box[closest_corners[1]][0]) / 2
        y_mid = (corners_of_box[closest_corners[0]][1] + corners_of_box[closest_corners[1]][1]) / 2
        self.get_logger().info(f"Midpoint: {x_mid}, {y_mid}")
        
        # Anlge from the midpoint to the center of the box
        angle = np.arctan2(center_of_box[1] - y_mid, center_of_box[0] - x_mid)
        self.get_logger().info(f"Angle: {angle}")
        
        # Vector from the midpoint to the center of the box
        vector = [center_of_box[0] - x_mid, center_of_box[1] - y_mid]
        vector = vector / np.linalg.norm(vector)
        self.get_logger().info(f"Vector: {vector}")
        
        # Desired position is the midpoint plus a margin in the opposite 
        # direction of the center of the box
        desired_position = [x_mid - margin * vector[0], y_mid - margin * vector[1]]
        
        self.get_logger().info(f"Moving to {desired_position}")
        
        self.move_to_goal([desired_position[0], desired_position[1], angle, True, False])
        
        # Sleep for a bit to let the robot settle and update frames
        time.sleep(2.0)
        
        # Move arm out of way of camera
        # TODO: Move arm code here
        
        # Get /tf/camera_locobot_link in world frame
        transform = self.tf_buffer.lookup_transform('world', 'camera_locobot_link', rclpy.time.Time())
        # self.get_logger().info(f"Transform: {transform}")
        
        horizontal_distance = np.sqrt((center_of_box[0] - transform.transform.translation.x)**2 +
                                        (center_of_box[1] - transform.transform.translation.y)**2)
        
        # Calculate angle from camera locobot link frame to the center of the box
        angle = np.arctan2(transform.transform.translation.z,
                            horizontal_distance)
        
        # Tilt camera down to look at the center of the box
        self.get_logger().info(f"Looking at the center of the box with angle {angle}")
        self.move_camera(0.0, angle)
        
        self.move_next_to_center_box_done_event.set_result(True)

    def move_camera(self, pan, tilt):
        # Positive tilt is down
        # Positive pan is left
        msg = Float64MultiArray()
        msg.data = [pan, tilt]
        self.mobile_camera_publisher.publish(msg)
        time.sleep(2.5)

    def find_april_tags(self, list_of_poses=[[-1.0, 0.0, 0.0]]):
        # Attempt to find the april tags.
        # We will accomplish this by first panning the camera, then we will rotate the base
        # and move the camera again.
        
        self.move_camera(0.0, 0.35) # down ~20 deg, straight ahead
        self.move_camera(0.5, 0.35) # down ~20 deg, left ~30 degrees
        self.move_camera(-0.5, 0.35) # down ~20 deg, right ~30 degrees
        self.move_camera(1.4, 0.35) # down ~20 deg, left ~80 degrees
        self.move_camera(-1.4, 0.35) # Straight ahead
        self.move_camera(0.0, 0.0) # Straight ahead
        
        # Move the base and then lookaround again
        for pose_i in list_of_poses:
            goal = [pose_i[0], pose_i[1], pose_i[2], True, False]
            self.move_to_goal(goal)
            
            self.move_camera(0.0, 0.35) # down ~20 deg, straight ahead
            self.move_camera(0.5, 0.35) # down ~20 deg, left ~30 degrees
            self.move_camera(-0.5, 0.35) # down ~20 deg, right ~30 degrees
            self.move_camera(1.4, 0.35) # down ~20 deg, left ~80 degrees
            self.move_camera(-1.4, 0.35) # Straight ahead
            self.move_camera(0.0, 0.0) # Straight ahead
        
        # Rotate the base 180 degrees (yaw to 0)
        goal = [0.0, 0.0, 0.0, True, False]
        self.move_to_goal(goal)

        
        # Verify we found the list of positions
        all_tags_found = True
        for position in LIST_OF_POSITIONS:
            if getattr(self, f'{position}_pose') is None:
                self.get_logger().warn(f"Did not find {position}")
                all_tags_found = False
        self.find_april_tag_done_event.set_result(all_tags_found)

    def destroy_april_tag_subscriptions(self):
        self.destroy_subscription(self.center_tr_pose)
        self.destroy_subscription(self.center_tl_pose)
        self.destroy_subscription(self.center_br_pose)
        self.destroy_subscription(self.center_bl_pose)
        self.destroy_subscription(self.a_build_a_pose)
        self.destroy_subscription(self.a_build_b_pose)
        self.destroy_subscription(self.b_build_a_pose)
        self.destroy_subscription(self.b_build_b_pose)

def main(args=None):
    rclpy.init(args=args)
    state_machine = StateMachine()
    
    executor = MultiThreadedExecutor()
    executor.add_node(state_machine)

    # Run find_april_tags in a separate thread
    april_thread = threading.Thread(target=state_machine.find_april_tags)
    april_thread.start()

    executor.spin_until_future_complete(state_machine.find_april_tag_done_event)

    # Wait for the april_tag_thread to finish
    april_thread.join()
    if state_machine.find_april_tag_done_event.result():
        state_machine.get_logger().info("All tags found!")
        # We now don't need the subscriptions to the april tag locations
        state_machine.destroy_april_tag_subscriptions()
    else:
        state_machine.get_logger().warn("Not all tags found")
        
    # We need to repeat this process x times, where x is the number of objects we need
    # to pick up and place.
    # for object_of_interest in state_machine.objects_of_interest:
    move_near_center_box_thread = threading.Thread(target=state_machine.move_next_to_center_box, args=(0.35,))
    move_near_center_box_thread.start()
    
    executor.spin_until_future_complete(state_machine.move_next_to_center_box_done_event)
    move_near_center_box_thread.join()
    
    #TODO 
    # Use the percpetion service to find the object of interest
    
    #TODO
    # Use the arm to pickup the object of interest
    
    #TODO
    # Move the robot to the dropoff location
    
    # TODO
    # Use the arm to dropoff the object of interest at the designated dropoff location
    
    

if __name__ == '__main__':
    main()