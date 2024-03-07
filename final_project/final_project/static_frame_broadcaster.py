import rclpy
from rclpy.node import Node
import rclpy.logging
from tf2_ros.static_transform_broadcaster import StaticTransformBroadcaster
from geometry_msgs.msg import TransformStamped
import tf_transformations

class StaticFramePublisher(Node):
    def __init__(self):
        super().__init__('static_frame_publisher')
        
        self._broadcaster = StaticTransformBroadcaster(self)
        self.publish_transform()

    def publish_transform(self):
        transform = TransformStamped()
        transform.header.stamp = self.get_clock().now().to_msg()
        transform.header.frame_id = 'camera_locobot_link'
        transform.child_frame_id = 'camera_image_frame'
        
        # Example transformation: rotate 90 degrees around X then 90 degrees around Y
        q = tf_transformations.quaternion_from_euler(-1.5708, -1.5708, 0, 'sxzy')
        transform.transform.rotation.x = q[0]
        transform.transform.rotation.y = q[1]
        transform.transform.rotation.z = q[2]
        transform.transform.rotation.w = q[3]

        # No translation in this example
        transform.transform.translation.x = 0.0
        transform.transform.translation.y = 0.0
        transform.transform.translation.z = 0.0

        self._broadcaster.sendTransform(transform)

def main(args=None):
    rclpy.init(args=args)
    node = StaticFramePublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    rclpy.shutdown()

if __name__ == '__main__':
    main()