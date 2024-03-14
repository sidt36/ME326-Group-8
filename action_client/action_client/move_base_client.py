#!/usr/bin/env python3
import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from geometry_msgs.msg import Point
from std_msgs.msg import Float64
from std_msgs.msg import Bool
from project_messages.action import MoveToPose
from action_msgs.msg import GoalStatus

class MoveActionClient(Node):

    def __init__(self):
        super().__init__('move_base_client')
        self._action_client = ActionClient(self, MoveToPose, 'move_to_pose')

    def send_goal(self, cmd_x, cmd_y, cmd_yaw=None, yaw_req=False, yaw_only=False):
        goal_msg = MoveToPose.Goal()

        position  = Point()
        position.x = cmd_x
        position.y = cmd_y
        goal_msg.position = position

        yaw = Float64()
        if cmd_yaw == None:
            yaw.data = 0.0
        else:
            yaw.data = cmd_yaw
        goal_msg.yaw = yaw.data
        
        orientation_required = Bool()
        orientation_required.data = yaw_req
        yaw_only_flag = Bool()
        yaw_only_flag.data = yaw_only
        
        goal_msg.orientation_required = orientation_required.data
        goal_msg.yaw_only = yaw_only_flag.data
        
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
        self.status = GoalStatus.STATUS_SUCCEEDED
        self.get_logger().info('Result: {0}'.format(result.pose_reached))

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info('Received feedback: {0}'.format(feedback.feedback_string))

