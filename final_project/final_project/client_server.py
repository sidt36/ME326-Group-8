import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from geometry_msgs.msg import Point
from std_msgs.msg import Float64
from std_msgs.msg import Bool
from pose_traj_controller.action import MoveToPose

class StateMachine(Node):

    def __init__(self):
        super().__init__('ActionClient')
        self._action_client = ActionClient(self, MoveToPose, 'move_to_pose')

    def send_goal(self, d):
        goal_msg = MoveToPose.Goal()

        position  = Point()

        position.x = float(d)
        position.y = 0.0

        goal_msg.position = position

        yaw = Float64()
        yaw.data = 0.2
        goal_msg.yaw = yaw.data

        orientation_required = Bool()
        orientation_required.data = True

        goal_msg.orientation_required = orientation_required.data

        self._action_client.wait_for_server()

        self._send_goal_future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)

        self._send_goal_future.add_done_callback(self.goal_response_callback)

        return self._action_client.send_goal_async(goal_msg)
    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected')
            return

        self.get_logger().info('Goal accepted')

        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info('Result: {0}'.format(result.sequence))
        rclpy.shutdown()

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info('Received feedback: {0}'.format(feedback.partial_sequence))



def main(args=None):
    rclpy.init(args=args)

    action_client = StateMachine()

    future = action_client.send_goal(5)

    rclpy.spin(action_client)



if __name__ == '__main__':
    main()