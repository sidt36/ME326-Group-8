import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from visualization_msgs.msg import Marker
from tf2_ros import Buffer, TransformListener

class PoseEstimatorNode(Node):
    def __init__(self):
        super().__init__('pose_estimator_node')
        # Declare parameters
        self.declare_parameter('tag_family', 'tag36h11')
        self.declare_parameter('tag_id', 0)
        self.declare_parameter('desired_pose_frame', 'odom')
        
        # Use parameters
        tag_family = self.get_parameter('tag_family').get_parameter_value().string_value
        tag_id = self.get_parameter('tag_id').get_parameter_value().integer_value
        
        self.declare_parameter('new_node_topic_name', f'tag_{tag_id}_pose')
        new_node_topic_name = self.get_parameter('new_node_topic_name').get_parameter_value().string_value
        self.new_node_topic_name = new_node_topic_name
        
        
        # Example: Construct the tag frame name using the family and ID
        self.tracked_tag_frame = f"{tag_family}:{tag_id}"
        
        # The frame you want to express the pose in
        self.odom_frame = self.get_parameter('desired_pose_frame').get_parameter_value().string_value
        
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.pose_publisher = self.create_publisher(PoseStamped, new_node_topic_name, 10)
        
        self.timer = self.create_timer(0.5, self.update_pose)
        self.timer = self.create_timer(1.0, self.publish_pose)
        
        self.pose = PoseStamped()
        self.estimated = True
        self.last_updated = self.get_clock().now()

        # Marker publisher for displaying pose names
        self.marker_publisher = self.create_publisher(Marker, 'visualization_marker', 10)

    def publish_marker_with_pose(self):
        # Create and publish the label as a Marker
        marker = Marker()
        marker.header.frame_id = self.pose.header.frame_id
        marker.header.stamp = self.pose.header.stamp
        marker.ns = "pose_labels"
        marker.id = hash(self.new_node_topic_name) % 2147483647  # Ensure ID is within the valid range
        marker.type = Marker.TEXT_VIEW_FACING
        marker.action = Marker.ADD
        marker.pose.position.x = self.pose.pose.position.x
        marker.pose.position.y = self.pose.pose.position.y
        marker.pose.position.z = self.pose.pose.position.z + -0.1  # Offset below the pose
        marker.scale.z = 0.1  # Text size
        marker.text = self.new_node_topic_name
        marker.color.a = 0.7  
        marker.color.r = 1.0
        marker.color.g = 1.0
        marker.color.b = 1.0
        self.marker_publisher.publish(marker)

    def publish_pose(self):
        self.pose_publisher.publish(self.pose)
        self.publish_marker_with_pose()

    def update_pose(self):
        try:
            if self.tf_buffer.can_transform(self.odom_frame, self.tracked_tag_frame, rclpy.time.Time()):
                # Look up the transform from the odom frame to the tag frame
                # at the latest available time.
                trans = self.tf_buffer.lookup_transform(self.odom_frame, self.tracked_tag_frame, rclpy.time.Time())
            
                # Create a PoseStamped message to publish the pose
                pose_stamped = PoseStamped()
                pose_stamped.header.stamp = self.get_clock().now().to_msg()
                pose_stamped.header.frame_id = self.odom_frame
                pose_stamped.pose.position.x = trans.transform.translation.x
                pose_stamped.pose.position.y = trans.transform.translation.y
                pose_stamped.pose.position.z = trans.transform.translation.z
                pose_stamped.pose.orientation = trans.transform.rotation
                
                self.pose = pose_stamped
                self.estimated = False
                self.last_updated = self.get_clock().now()
                
                # self.get_logger().info(f'Published updated pose of {self.tracked_tag_frame}')
        
        except Exception as e:
            self.get_logger().info(f'Could not transform {self.tracked_tag_frame} to {self.odom_frame}: {e}')

def main(args=None):
    rclpy.init(args=args)
    node = PoseEstimatorNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        rclpy.shutdown()

if __name__ == '__main__':
    main()
