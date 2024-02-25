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
                '-entity', 'red_cube1', 
                '-file', f'{model_path}/red_cube.urdf',
                '-x', '1.1', 
                '-y', '0.5', 
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
                '-entity', 'red_cube2', 
                '-file', f'{model_path}/red_cube.urdf',
                '-x', '1.2', 
                '-y', '0.4', 
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
                '-entity', 'red_cube3', 
                '-file', f'{model_path}/red_cube.urdf',
                '-x', '1.3', 
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
                '-entity', 'red_cube4', 
                '-file', f'{model_path}/red_cube.urdf',
                '-x', '1.4', 
                '-y', '0.2', 
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
                '-entity', 'blue_cube1', 
                '-file', f'{model_path}/blue_cube.urdf',
                '-x', '1.2', 
                '-y', '0.5', 
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
                '-entity', 'blue_cube2', 
                '-file', f'{model_path}/blue_cube.urdf',
                '-x', '1.3', 
                '-y', '0.4', 
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
                '-entity', 'blue_cube3', 
                '-file', f'{model_path}/blue_cube.urdf',
                '-x', '1.4', 
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
                '-entity', 'blue_cube4', 
                '-file', f'{model_path}/blue_cube.urdf',
                '-x', '1.1', 
                '-y', '0.2', 
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
                '-entity', 'yellow_cube1', 
                '-file', f'{model_path}/yellow_cube.urdf',
                '-x', '1.3', 
                '-y', '0.5', 
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
                '-entity', 'yellow_cube2', 
                '-file', f'{model_path}/yellow_cube.urdf',
                '-x', '1.4', 
                '-y', '0.4', 
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
                '-entity', 'yellow_cube3', 
                '-file', f'{model_path}/yellow_cube.urdf',
                '-x', '1.1', 
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
                '-entity', 'yellow_cube4', 
                '-file', f'{model_path}/yellow_cube.urdf',
                '-x', '1.2', 
                '-y', '0.2', 
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
                '-entity', 'green_cube1', 
                '-file', f'{model_path}/green_cube.urdf',
                '-x', '1.4', 
                '-y', '0.5', 
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
                '-entity', 'green_cube2', 
                '-file', f'{model_path}/green_cube.urdf',
                '-x', '1.1', 
                '-y', '0.4', 
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
                '-entity', 'green_cube3', 
                '-file', f'{model_path}/green_cube.urdf',
                '-x', '1.2', 
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
                '-entity', 'green_cube4', 
                '-file', f'{model_path}/green_cube.urdf',
                '-x', '1.3', 
                '-y', '0.2', 
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
                '-entity', 'red_cube5', 
                '-file', f'{model_path}/red_cube.urdf',
                '-x', '1.1', 
                '-y', '-0.5', 
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
                '-entity', 'red_cube6', 
                '-file', f'{model_path}/red_cube.urdf',
                '-x', '1.2', 
                '-y', '-0.4', 
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
                '-entity', 'red_cube7', 
                '-file', f'{model_path}/red_cube.urdf',
                '-x', '1.3', 
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
                '-entity', 'red_cube8', 
                '-file', f'{model_path}/red_cube.urdf',
                '-x', '1.4', 
                '-y', '-0.2', 
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
                '-entity', 'blue_cube5', 
                '-file', f'{model_path}/blue_cube.urdf',
                '-x', '1.2', 
                '-y', '-0.5', 
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
                '-entity', 'blue_cube6', 
                '-file', f'{model_path}/blue_cube.urdf',
                '-x', '1.3', 
                '-y', '-0.4', 
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
                '-entity', 'blue_cube7', 
                '-file', f'{model_path}/blue_cube.urdf',
                '-x', '1.4', 
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
                '-entity', 'blue_cube8', 
                '-file', f'{model_path}/blue_cube.urdf',
                '-x', '1.1', 
                '-y', '-0.2', 
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
                '-entity', 'yellow_cube5', 
                '-file', f'{model_path}/yellow_cube.urdf',
                '-x', '1.3', 
                '-y', '-0.5', 
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
                '-entity', 'yellow_cube6', 
                '-file', f'{model_path}/yellow_cube.urdf',
                '-x', '1.4', 
                '-y', '-0.4', 
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
                '-entity', 'yellow_cube7', 
                '-file', f'{model_path}/yellow_cube.urdf',
                '-x', '1.1', 
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
                '-entity', 'yellow_cube8', 
                '-file', f'{model_path}/yellow_cube.urdf',
                '-x', '1.2', 
                '-y', '-0.2', 
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
                '-entity', 'green_cube5', 
                '-file', f'{model_path}/green_cube.urdf',
                '-x', '1.4', 
                '-y', '-0.5', 
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
                '-entity', 'green_cube6', 
                '-file', f'{model_path}/green_cube.urdf',
                '-x', '1.1', 
                '-y', '-0.4', 
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
                '-entity', 'green_cube7', 
                '-file', f'{model_path}/green_cube.urdf',
                '-x', '1.2', 
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
                '-entity', 'green_cube8', 
                '-file', f'{model_path}/green_cube.urdf',
                '-x', '1.3', 
                '-y', '-0.2', 
                '-z', '0.1',
                '-R', '0.0',
                '-P', '0.0',
                '-Y', '0.0'],
            output='screen'
        ),
    ])