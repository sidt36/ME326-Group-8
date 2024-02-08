from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from ament_index_python import get_package_share_directory
import os

def generate_launch_description():
    model_path = os.path.join(get_package_share_directory('final_project'), 'model')
    return LaunchDescription([
        Node(
                package='gazebo_ros',
                executable='spawn_entity.py',
                arguments=[
                    '-entity', 'blue_cube', 
                    '-file', f'{model_path}/blue_cube.urdf',
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
                    '-file', f'{model_path}/red_cube.urdf',
                    '-x', '1.5', 
                    '-y', '0.3', 
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
                    '-entity', 'green_cube', 
                    '-file', f'{model_path}/green_cube.urdf',
                    '-x', '1.5', 
                    '-y', '-0.3', 
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
                    '-entity', 'yellow_cube', 
                    '-file', f'{model_path}/yellow_cube.urdf',
                    '-x', '1.8', 
                    '-y', '0.0', 
                    '-z', '0.1',
                    '-R', '0.0',
                    '-P', '0.0',
                    '-Y', '0.0'],
                output='screen'
            )
    ])