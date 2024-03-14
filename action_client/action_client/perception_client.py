#!/usr/bin/env python3

import sys
from la_msgs.srv import Ptps
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PointStamped, Pose
import tf2_geometry_msgs
import time
from rclpy.executors import Future

class PerceptionClient(Node):

    def __init__(self):
        
        super().__init__('perception_client')
        self.get_logger().info('Perception Client Node Started')
        self.cli = self.create_client(Ptps, 'pix_to_point_cpp')
        while not self.cli.wait_for_service(timeout_sec=2.0):
            self.get_logger().info('service not available, waiting again...')
            
        self.req = Ptps.Request()

    def send_request(self, frame):
        self.req.desired_frame = frame
        self.get_logger().info('Sending request...')
        self.future = self.cli.call_async(self.req)


    def closest_blocks(self, block_color, tf_buffer, tf_time):
        '''
        Input: Desired frame, Base X , Y in the desired frame
        Returns: R G B Y List[X, Y, Z] or None if not found
        This function is used to call the perception service and get the closest blocks to the camera.
        '''

        block_pos = None
        
        max_tries = 5
        tries = 0
        
        any_present = True
        total_points = 0
        
        while (any_present and total_points == 0) and tries < max_tries:
            
            self.send_request('locobot/camera_depth_link')
            rclpy.spin_until_future_complete(self, self.future)

            response = self.future.result()

            red_points = response.red_points
            blue_points = response.blue_points
            green_points = response.green_points
            yellow_points = response.yellow_points
            
            any_present = response.red_present or response.blue_present or response.green_present or response.yellow_present
            total_points = len(red_points) + len(blue_points) + len(green_points) + len(yellow_points)
            
            self.get_logger().info(f'Any blocks present: {any_present}')
            self.get_logger().info(f'Total blocks present: {total_points}')
            
            tries = tries + 1
            
            if (any_present and total_points == 0):
                self.get_logger().info('No points found, trying again. Try: ' + str(tries))
            
            if not any_present:
                break
        
        transform = tf_buffer.lookup_transform('locobot/base_link', 'locobot/camera_depth_link', tf_time)
        self.get_logger().info(f'Transform obtained: {transform}')
        
        if block_color == 'red':
            points = red_points
        elif block_color == 'blue':
            points = blue_points
        elif block_color == 'green':
            points = green_points
        elif block_color == 'yellow':
            points = yellow_points
        else:
            # Thow an error for invalid block color
            self.get_logger().error('Invalid block color')
            block_pos = None
            
        if len(points) > 0:
            min_distance = 100000
            for point in points:
                pose = Pose()
                pose.position.x = point.point.x
                pose.position.y = point.point.y
                pose.position.z = point.point.z
                pose_in_locobot_frame = tf2_geometry_msgs.do_transform_pose(pose, transform)
                
                distance = (pose_in_locobot_frame.position.x)**2 + (pose_in_locobot_frame.position.y)**2
                if(distance < min_distance):
                    min_distance = distance
                    closest_block = [pose_in_locobot_frame.position.x, pose_in_locobot_frame.position.y, pose_in_locobot_frame.position.z]
            block_pos = closest_block
        else:
            block_pos = None
            self.get_logger().warn(f'No {block_color} cubes found')
        
        return block_pos
    
    def all_blocks_world(self, tf_buffer, tf_time):

        max_tries = 5
        tries = 0        
        any_present = True
        total_points = 0
        
        while (any_present and total_points == 0) and tries < max_tries:
            
            self.send_request('locobot/camera_depth_link')
            rclpy.spin_until_future_complete(self, self.future)

            response = self.future.result()

            red_points = response.red_points
            blue_points = response.blue_points
            green_points = response.green_points
            yellow_points = response.yellow_points
            
            any_present = response.red_present or response.blue_present or response.green_present or response.yellow_present
            total_points = len(red_points) + len(blue_points) + len(green_points) + len(yellow_points)
            
            self.get_logger().info(f'Any blocks present: {any_present}')
            self.get_logger().info(f'Total blocks present: {total_points}')
            
            tries = tries + 1
            
            if (any_present and total_points == 0):
                self.get_logger().info('No points found, trying again. Try: ' + str(tries))
            
            if not any_present:
                break
        
        transform = tf_buffer.lookup_transform('world', 'locobot/camera_depth_link', tf_time)
        self.get_logger().info(f'Transform obtained: {transform}')
        
        red_points_tfd = []
        blue_points_tfd = []
        green_points_tfd = []
        yellow_points_tfd = []
        
        if len(red_points) > 0:
            for point in red_points:
                pose = Pose()
                pose.position.x = point.point.x
                pose.position.y = point.point.y
                pose.position.z = point.point.z
                pose_in_locobot_frame = tf2_geometry_msgs.do_transform_pose(pose, transform)
                red_points_tfd.append([pose_in_locobot_frame.position.x, pose_in_locobot_frame.position.y, pose_in_locobot_frame.position.z])
        
        if len(blue_points) > 0:
            for point in blue_points:
                pose = Pose()
                pose.position.x = point.point.x
                pose.position.y = point.point.y
                pose.position.z = point.point.z
                pose_in_locobot_frame = tf2_geometry_msgs.do_transform_pose(pose, transform)
                blue_points_tfd.append([pose_in_locobot_frame.position.x, pose_in_locobot_frame.position.y, pose_in_locobot_frame.position.z])
        
        if len(green_points) > 0:
            for point in green_points:
                pose = Pose()
                pose.position.x = point.point.x
                pose.position.y = point.point.y
                pose.position.z = point.point.z
                pose_in_locobot_frame = tf2_geometry_msgs.do_transform_pose(pose, transform)
                green_points_tfd.append([pose_in_locobot_frame.position.x, pose_in_locobot_frame.position.y, pose_in_locobot_frame.position.z])
        
        if len(yellow_points) > 0:
            for point in yellow_points:
                pose = Pose()
                pose.position.x = point.point.x
                pose.position.y = point.point.y
                pose.position.z = point.point.z
                pose_in_locobot_frame = tf2_geometry_msgs.do_transform_pose(pose, transform)
                yellow_points_tfd.append([pose_in_locobot_frame.position.x, pose_in_locobot_frame.position.y, pose_in_locobot_frame.position.z])
    
        return red_points_tfd, blue_points_tfd, green_points_tfd, yellow_points_tfd