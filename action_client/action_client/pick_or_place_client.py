#!/usr/bin/env python3
import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from project_messages.action import PickOrPlace
from action_msgs.msg import GoalStatus

class PickOrPlaceActionClient(Node):

    def __init__(self):
        super().__init__('pick_or_place_client')
        self._action_client = ActionClient(self, PickOrPlace, 'arm_pick_or_place')

    def send_goal(self, pose, pick_or_place):
        goal_msg = PickOrPlace.Goal()
        
        goal_msg.pose = pose
        goal_msg.pick_or_place = pick_or_place
        
        self.status = GoalStatus.STATUS_EXECUTING        
        self._action_client.wait_for_server()
        self._send_goal_future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        self.status = GoalStatus.STATUS_EXECUTING
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected')
            return
        self.get_logger().info('Goal accepted')
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        if result.success == False:
            self.status = GoalStatus.STATUS_ABORTED
        else:
            self.status = GoalStatus.STATUS_SUCCEEDED
        self.get_logger().info('Result: {0}'.format(result.success))

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info('Received feedback: {0}'.format(feedback.feedback_string))
        
# def main(args=None):
#     rclpy.init(args=args)
#     action_client = PickOrPlaceActionClient()
#     pose = [0.3, 0.05, 0.01]
#     action_client.send_goal(pose, True)
#     rclpy.spin(action_client)
#     action_client.destroy_node()
#     rclpy.shutdown()
    
# if __name__ == '__main__':
#     main()