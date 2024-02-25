from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from ament_index_python import get_package_share_directory
import os

def generate_launch_description():
    # Path to ~/.gazebo/models
    models_path = os.path.expanduser('~/.gazebo/models')
    
    return LaunchDescription([
        Node(
            package='gazebo_ros',
            executable='spawn_entity.py',
            arguments=[
                '-entity', 'apriltag_0', 
                '-file', f'{models_path}/Apriltag36_11_00000/model.sdf',
                '-x', '0.0', 
                '-y', '1.0', 
                '-z', '0.0',
                '-R', '0.0',
                '-P', '0.0',
                '-Y', '0.0'],
            output='screen'
        ),
        Node(
            package='gazebo_ros',
            executable='spawn_entity.py',
            arguments=[
                '-entity', 'apriltag_1', 
                '-file', f'{models_path}/Apriltag36_11_00001/model.sdf',
                '-x', '0.0', 
                '-y', '-1.0', 
                '-z', '0.0',
                '-R', '0.0',
                '-P', '0.0',
                '-Y', '3.1416'],
            output='screen'
        ),
        Node(
            package='gazebo_ros',
            executable='spawn_entity.py',
            arguments=[
                '-entity', 'apriltag_2', 
                '-file', f'{models_path}/Apriltag36_11_00002/model.sdf',
                '-x', '1.25', 
                '-y', '0.0', 
                '-z', '0.0',
                '-R', '0.0',
                '-P', '0.0',
                '-Y', '0.0'],
            output='screen'
        ),
        Node(
            package='gazebo_ros',
            executable='spawn_entity.py',
            arguments=[
                '-entity', 'apriltag_3', 
                '-file', f'{models_path}/Apriltag36_11_00003/model.sdf',
                '-x', '2.5', 
                '-y', '1.0', 
                '-z', '0.0',
                '-R', '0.0',
                '-P', '0.0',
                '-Y', '0.0'],
            output='screen'
        ),
        Node(
            package='gazebo_ros',
            executable='spawn_entity.py',
            arguments=[
                '-entity', 'apriltag_4', 
                '-file', f'{models_path}/Apriltag36_11_00004/model.sdf',
                '-x', '2.5', 
                '-y', '-1.0', 
                '-z', '0.0',
                '-R', '0.0',
                '-P', '0.0',
                '-Y', '3.1416'],
            output='screen'
        )
    ])