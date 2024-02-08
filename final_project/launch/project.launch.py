import os
import time
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from ament_index_python import get_package_share_directory

from launch_ros.actions import Node

# Declare constanct for sim file path
SIM_FILE_PATH = '~/interbotix_ws/src/interbotix_ros_rovers/interbotix_ros_xslocobots/interbotix_xslocobot_sim/launch'

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
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    os.path.join(get_package_share_directory('final_project'), 
                                 'launch/spawn_cube.launch.py')
                )
            )
        ])
    ])


