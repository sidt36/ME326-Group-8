#!/usr/bin/env python3
import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
# from std_msgs.msg import String
from project_messages.action import MoveArmToNamedPose
from action_msgs.msg import GoalStatus

class MoveArmNamedPoseActionClient(Node):

    def __init__(self):
        super().__init__('move_arm_named_pose_client')
        self._action_client = ActionClient(self, MoveArmToNamedPose, 'move_arm_named_pose')
        self.execution_attempts = 0
        self._pose_name = None

    def send_goal(self, pose_name):
        self._pose_name = pose_name
        goal_msg = MoveArmToNamedPose.Goal()
        goal_msg.pose = pose_name
        self.execution_attempts = 0
        
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
        # If aborted, retry if execution attemps are less than 2
        if not result.success and self.execution_attempts < 2:
            self.execution_attempts += 1
            self.get_logger().info('Retrying to execute the pose. Attempt number {0}'.format(self.execution_attempts))
            self.send_goal(self._pose_name)
            return
        
        # Set status based on result (ABORTED or SUCCEEDED or FAILED)
        if result.success == False:
            self.status = GoalStatus.STATUS_ABORTED
        else:
            self.status = GoalStatus.STATUS_SUCCEEDED
        self.get_logger().info('Result: {0}'.format(result.success))

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info('Received feedback: {0}'.format(feedback.feedback_string))