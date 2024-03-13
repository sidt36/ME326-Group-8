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
    use_moveit_rviz_arg = DeclareLaunchArgument('use_moveit_rviz', default_value='true')
    world_file = os.path.join(get_package_share_directory('final_project'), 'worlds', 'final_project.world')
    world_file_arg = DeclareLaunchArgument('world', default_value=world_file)
    rviz_config_file = os.path.join(get_package_share_directory('final_project'), 'config', 'final_project.rviz')
    rviz_config_file_arg = DeclareLaunchArgument('rviz_config_file', default_value=rviz_config_file)

    return LaunchDescription([
        robot_model_arg,
        use_lidar_arg,
        hardware_type_arg,
        use_moveit_rviz_arg,
        world_file_arg,
        rviz_config_file_arg,
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.expanduser(f'{SIM_FILE_PATH}/xslocobot_moveit.launch.py')),
            launch_arguments={
                'robot_model': LaunchConfiguration('robot_model'),
                'use_lidar': LaunchConfiguration('use_lidar'),
                'hardware_type': LaunchConfiguration('hardware_type'),
                'use_moveit_rviz': LaunchConfiguration('use_moveit_rviz'),
                'rviz_config_file': LaunchConfiguration('rviz_config_file'),
                'world_filepath': LaunchConfiguration('world')
            }.items()
        ),
        TimerAction(period=5.0, actions=[
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    os.path.join(get_package_share_directory('final_project'), 
                                 'launch/spawn_cube.launch.py')
                )
            ),
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    os.path.join(get_package_share_directory('final_project'), 
                                 'launch/spawn_april_tags.launch.py')
                )
            ),
            Node(
                package='final_project',
                executable='static_frame_broadcaster',
                name='static_frame_broadcaster_node',
                output='screen',
                parameters=[{'use_sim_time': True}],
            )
        ]),
        TimerAction(period=6.0, actions=[
            Node(
                package='final_project',
                executable='world_publisher',
                name='world_publisher_node',
                output='screen',
                parameters=[{'use_sim_time': True}],
            ),
            Node(
                package='pose_traj_controller',
                executable='pose_traj_controller',
                name='pose_traj_controller_node',
                output='screen',
                parameters=[{'use_sim_time': True}],
            ),
            Node(
                package='move_group_interface',
                executable='move_group_interface_named_pose_server',
                name='move_group_interface_named_pose_server',
                output='screen',
                parameters=[{'use_sim_time': True}],
            ),
            Node(
                package='move_group_interface',
                executable='move_group_interface_pick_or_place_server',
                name='move_group_interface_pose_pick_or_place_server',
                output='screen',
                parameters=[{'use_sim_time': True}],
            ),
            Node(
                package='locobot_autonomy',
                executable='visual_block_perception_srv',
                name='visual_block_perception_srv',
                output='screen',
                parameters=[{'use_sim_time': True}],
            ),
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    os.path.join(get_package_share_directory('apriltag_ros'), 
                                 'launch/apriltag.launch.py')
                )
            )
        ]),
        TimerAction(period=7.0, actions=[
            Node(
                package='final_project',
                executable='dummy_subscriber',
                name='dummy_subscriber_node',
                output='screen',
                parameters=[{'use_sim_time': True}],
            ),
            Node(
                package='final_project',
                executable='pose_estimator',
                name='pose_estimator_node',
                parameters=[{
                    'tag_family': 'tag36h11',
                    'tag_id': 0,
                    'desired_pose_frame': 'world',
                    'new_node_topic_name': 'a_build_a',
                    'use_sim_time': True
            }],
                output='screen',
            ),
            Node(
                package='final_project',
                executable='pose_estimator',
                name='pose_estimator_node',
                parameters=[{
                    'tag_family': 'tag36h11',
                    'tag_id': 1,
                    'desired_pose_frame': 'world',
                    'new_node_topic_name': 'a_build_b',
                    'use_sim_time': True
            }],
                output='screen',
            ),
            Node(
                package='final_project',
                executable='pose_estimator',
                name='pose_estimator_node',
                parameters=[{
                    'tag_family': 'tag36h11',
                    'tag_id': 2,
                    'desired_pose_frame': 'world',
                    'new_node_topic_name': 'b_build_a',
                    'use_sim_time': True
            }],
                output='screen',
            ),
            Node(
                package='final_project',
                executable='pose_estimator',
                name='pose_estimator_node',
                parameters=[{
                    'tag_family': 'tag36h11',
                    'tag_id': 3,
                    'desired_pose_frame': 'world',
                    'new_node_topic_name': 'b_build_b',
                    'use_sim_time': True
            }],
                output='screen',
            ),
            Node(
                package='final_project',
                executable='pose_estimator',
                name='pose_estimator_node',
                parameters=[{
                    'tag_family': 'tag36h11',
                    'tag_id': 4,
                    'desired_pose_frame': 'world',
                    'new_node_topic_name': 'center_tl',
                    'use_sim_time': True
            }],
                output='screen',
            ),
            Node(
                package='final_project',
                executable='pose_estimator',
                name='pose_estimator_node',
                parameters=[{
                    'tag_family': 'tag36h11',
                    'tag_id': 5,
                    'desired_pose_frame': 'world',
                    'new_node_topic_name': 'center_tr',
                    'use_sim_time': True
            }],
                output='screen',
            ),
            Node(
                package='final_project',
                executable='pose_estimator',
                name='pose_estimator_node',
                parameters=[{
                    'tag_family': 'tag36h11',
                    'tag_id': 6,
                    'desired_pose_frame': 'world',
                    'new_node_topic_name': 'center_bl',
                    'use_sim_time': True
            }],
                output='screen',
            ),
            Node(
                package='final_project',
                executable='pose_estimator',
                name='pose_estimator_node',
                parameters=[{
                    'tag_family': 'tag36h11',
                    'tag_id': 7,
                    'desired_pose_frame': 'world',
                    'new_node_topic_name': 'center_br',
                    'use_sim_time': True
            }],
                output='screen',
            ),
        ])
    ])