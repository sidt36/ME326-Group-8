import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from geometry_msgs.msg import Point
from std_msgs.msg import Float64
from std_msgs.msg import Bool
from pose_traj_controller.action import MoveToPose
from action_msgs.msg import GoalStatus


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
        self.status = GoalStatus.STATUS_EXECUTING


        orientation_required = Bool()
        orientation_required.data = True

        goal_msg.orientation_required = orientation_required.data

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



def main(args=None):
    rclpy.init(args=args)

    action_client = StateMachine()

    goals = [-1, -2, 2]

    for goal in goals:

        action_client.send_goal(goal)

        while action_client.status != GoalStatus.STATUS_SUCCEEDED:
            rclpy.spin_once(action_client)


    rclpy.shutdown()



if __name__ == '__main__':
    main()
