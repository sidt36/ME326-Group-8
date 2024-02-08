import os
import time
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, ThisLaunchFileDir, PathJoinSubstitution

from launch_ros.actions import Node

# Declare constanct for sim file path
SIM_FILE_PATH = '~/interbotix_ws/src/interbotix_ros_rovers/interbotix_ros_xslocobots/interbotix_xslocobot_sim/launch'
MODEL_PATH = '~/model'

def generate_launch_description():
    robot_model_arg = DeclareLaunchArgument('robot_model', default_value='locobot_wx250s')
    use_lidar_arg = DeclareLaunchArgument('use_lidar', default_value='true')

    return LaunchDescription([
        robot_model_arg,
        use_lidar_arg,
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.expanduser(f'{SIM_FILE_PATH}/xslocobot_gz_classic.launch.py')),
            launch_arguments={
                'robot_model': LaunchConfiguration('robot_model'),
                'use_lidar': LaunchConfiguration('use_lidar')
            }.items()
        ),
        TimerAction(period=5.0, actions=[
            Node(
                package='gazebo_ros',
                executable='spawn_entity.py',
                arguments=[
                    '-entity', 'blue_cube', 
                    '-file', os.path.expanduser(f'{MODEL_PATH}/blue_cube.urdf'),
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
                    '-file', os.path.expanduser(f'{MODEL_PATH}/red_cube.urdf'),
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
                    '-file', os.path.expanduser(f'{MODEL_PATH}/green_cube.urdf'),
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
                    '-file', os.path.expanduser(f'{MODEL_PATH}/yellow_cube.urdf'),
                    '-x', '1.8', 
                    '-y', '0.0', 
                    '-z', '0.1',
                    '-R', '0.0',
                    '-P', '0.0',
                    '-Y', '0.0'],
                output='screen'
            )
        ])
    ])


