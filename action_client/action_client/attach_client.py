#!/usr/bin/env python3

import sys
import rclpy
from rclpy.node import Node
from gazebo_ros_link_attacher.srv import Attach

class AttachClient(Node):

    def __init__(self):
        
        super().__init__('attach_client')
        self.cli = self.create_client(Attach, '/attach')
        self.get_logger().info('Creating service to /attach')
        while not self.cli.wait_for_service(timeout_sec=2.0):
            self.get_logger().info('service not available, waiting...')
            
        self.req = Attach.Request()

    def send_request(self, cube_name):
        self.req.model_name_1 = 'robot_description'
        self.req.link_name_1 = 'locobot/right_finger_link'
        self.req.model_name_2 = cube_name
        self.req.link_name_2 = 'my_box'
        
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

class DetachClient(Node):

    def __init__(self):
        
        super().__init__('detach_client')
        self.cli = self.create_client(Attach, '/detach')
        self.get_logger().info('Creating service to /detach')
        while not self.cli.wait_for_service(timeout_sec=2.0):
            self.get_logger().info('service not available, waiting...')
            
        self.req = Attach.Request()

    def send_request(self, cube_name):
        self.req.model_name_1 = 'robot_description'
        self.req.link_name_1 = 'locobot/right_finger_link'
        self.req.model_name_2 = cube_name
        self.req.link_name_2 = 'my_box'
        
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

# if __name__ == '__main__':
#     rclpy.init(args=None)
#     minimal_client = PerceptionClient()
#     print(minimal_client.closest_blocks('world', 0, 0))
#     rclpy.shutdown()
