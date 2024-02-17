import os
import time
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from ament_index_python import get_package_share_directory

from launch_ros.actions import Node

# Declare constanct for sim file path
# SIM_FILE_PATH = '~/interbotix_ws/src/interbotix_ros_rovers/interbotix_ros_xslocobots/interbotix_xslocobot_sim/launch'
SIM_FILE_PATH = '~/interbotix_ws/src/interbotix_ros_rovers/interbotix_ros_xslocobots/interbotix_xslocobot_moveit/launch'

def generate_launch_description():
    robot_model_arg = DeclareLaunchArgument('robot_model', default_value='locobot_wx250s')
    use_lidar_arg = DeclareLaunchArgument('use_lidar', default_value='true')
    hardware_type_arg = DeclareLaunchArgument('hardware_type', default_value='gz_classic')

    return LaunchDescription([
        robot_model_arg,
        use_lidar_arg,
        hardware_type_arg,
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.expanduser(f'{SIM_FILE_PATH}/xslocobot_moveit.launch.py')),
            launch_arguments={
                'robot_model': LaunchConfiguration('robot_model'),
                'use_lidar': LaunchConfiguration('use_lidar'),
                'hardware_type': LaunchConfiguration('hardware_type'),
            }.items()
        ),
        TimerAction(period=5.0, actions=[
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    os.path.join(get_package_share_directory('final_project'), 
                                 'launch/spawn_cube.launch.py')
                )
            )
        ]),
        TimerAction(period=5.0, actions=[
            Node(
                package='pose_traj_controller',
                executable='pose_traj_controller',
                name='pose_traj_controller_node',
                output='screen',
            )
        ])
    ])


