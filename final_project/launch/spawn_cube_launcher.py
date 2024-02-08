from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='gazebo_ros',
            executable='spawn_entity.py',
            arguments=[
                '-entity', 'blue_cube', 
                '-file', '/path/to/your/blue_cube.urdf', 
                '-x', '1.5', 
                '-y', '0.0', 
                '-z', '0.1',
                '-R', '0.0',
                '-P', '0.0',
                '-Y', '0.0'],
            output='screen'
        ),
        Node(
            package='gazebo_ros',
            executable='spawn_entity.py',
            arguments=[
                '-entity', 'red_cube', 
                '-file', '/path/to/your/red_cube.urdf', 
                '-x', '1.5', 
                '-y', '0.3', 
                '-z', '0.1',
                '-R', '0.0',
                '-P', '0.0',
                '-Y', '0.0'],
            output='screen'
        )
        # Add similar Node instances for green_cube and yellow_cube
    ])