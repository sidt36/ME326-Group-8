#!/usr/bin/env python3
import sys

from la_msgs.srv import Ptps
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PointStamped

class PerceptionClient(Node):

    def __init__(self):
        
        super().__init__('perception_client')
        self.cli = self.create_client(Ptps, 'pix_to_point_cpp')
        while not self.cli.wait_for_service(timeout_sec=2.0):
            self.get_logger().info('service not available, waiting again...')
            
        self.req = Ptps.Request()

    def send_request(self, frame):
        self.req.desired_frame = frame
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()


    def closest_blocks(self, desired_frame = 'world', base_x = 0, base_y = 0):
        '''
        Input: Desired frame, Base X , Y in the desired frame
        Returns: R G B Y List[X, Y, Z] or None if not found
        This function is used to call the perception service and get the closest blocks to the camera.
        '''
        
        frame = desired_frame
        
        response = self.send_request(frame)


        red_points = response.red_points
        blue_points = response.blue_points
        green_points = response.green_points
        yellow_points = response.yellow_points

        if(response.red_present):
            min_distance = 100000
            for point in red_points:
                distance = (point.point.x - base_x)**2 + (point.point.y - base_y)**2
                if(distance < min_distance):
                    min_distance = distance
                    closest_red = [point.point.x, point.point.y, point.point.z]
            print('Closest Red Point: ',closest_red)
                
        else:
            print('No red points found') 
            closest_red = None


        if(response.blue_present):
            min_distance = 100000
            for point in blue_points:
                distance = (point.point.x - base_x)**2 + (point.point.y - base_y)**2
                if(distance < min_distance):
                    min_distance = distance
                    closest_blue = [point.point.x, point.point.y, point.point.z]
            print('Closest Blue Point: ',closest_blue)        

        else:
            print('No blue points found')
            closest_blue = None


        if(response.green_present):
            min_distance = 100000
            for point in green_points:
                distance = (point.point.x - base_x)**2 + (point.point.y - base_y)**2
                if(distance < min_distance):
                    min_distance = distance
                    closest_green = [point.point.x, point.point.y, point.point.z]
            print('Closest Green Point: ',closest_green)
            
        else:
            print('No green points found') 
            closest_green = None


        if(response.yellow_present):
            min_distance = 100000
            for point in yellow_points:
                distance = (point.point.x - base_x)**2 + (point.point.y - base_y)**2
                if(distance < min_distance):
                    min_distance = distance
                    closest_yellow = [point.point.x, point.point.y, point.point.z]
            print('Closest Yellow Point: ',closest_yellow)
                
        else:
            print('No yellow points found')  
            closest_yellow = None                         


        self.get_logger().info('Results Done!')

        self.destroy_node()
        

        return closest_red, closest_blue, closest_green, closest_yellow


if __name__ == '__main__':
    rclpy.init(args=None)
    minimal_client = PerceptionClient()
    print(minimal_client.closest_blocks('world', 0, 0))
    rclpy.shutdown()
