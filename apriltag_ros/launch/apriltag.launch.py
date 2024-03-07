from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    config = os.path.join(
        get_package_share_directory('apriltag_ros'),
        'cfg',
        'tags_36h11.yaml'
    )

    return LaunchDescription([
        Node(
            package='apriltag_ros',
            executable='apriltag_node',
            name='apriltag_ros',
            remappings=[
                ('image_rect', '/locobot/camera_frame_sensor/image_raw'),
                ('camera_info', '/locobot/camera_frame_sensor/camera_info'),
            ],
            parameters=[config],
        ),
    ])