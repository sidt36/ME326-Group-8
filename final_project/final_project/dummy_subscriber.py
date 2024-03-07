import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from rclpy.qos import QoSProfile, QoSHistoryPolicy, QoSReliabilityPolicy, QoSDurabilityPolicy

custom_qos_profile = QoSProfile(
    history=QoSHistoryPolicy.KEEP_LAST,
    depth=1,
    reliability=QoSReliabilityPolicy.BEST_EFFORT,
    durability=QoSDurabilityPolicy.VOLATILE
)

class DummySubscriber(Node):

    def __init__(self):
        super().__init__('dummy_subscriber')
        self.subscription = self.create_subscription(
            Image,
            'image_raw',
            self.listener_callback,
            custom_qos_profile)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        # This is where you would process the data, but we do nothing here
        pass

def main(args=None):
    rclpy.init(args=args)
    dummy_subscriber = DummySubscriber()
    rclpy.spin(dummy_subscriber)
    dummy_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()