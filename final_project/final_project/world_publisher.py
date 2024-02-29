import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped
from rclpy.qos import qos_profile_sensor_data

class WorldBaseLinkPublisher(Node):

    def __init__(self):
        super().__init__('world_baselink_tf2_broadcaster')
        self.subscription = self.create_subscription(
            Odometry,
            '/locobot/sim_ground_truth_pose',
            self.pose_callback,
            qos_profile_sensor_data
        )
        self.broadcaster = TransformBroadcaster(self)
        self.subscription  # prevent unused variable warning

    def pose_callback(self, msg: Odometry):
        transform = TransformStamped()

        transform.header.stamp = msg.header.stamp
        transform.header.frame_id = 'world'
        transform.child_frame_id = '/locobot/base_link'

        # Copying the pose information to the transform
        transform.transform.translation.x = msg.pose.pose.position.x
        transform.transform.translation.y = msg.pose.pose.position.y
        transform.transform.translation.z = msg.pose.pose.position.z
        transform.transform.rotation = msg.pose.pose.orientation

        # Broadcasting the transform
        self.broadcaster.sendTransform(transform)

def main(args=None):
    rclpy.init(args=args)
    node = WorldBaseLinkPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    rclpy.shutdown()

if __name__ == '__main__':
    main()
