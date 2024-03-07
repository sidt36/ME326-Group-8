
import os
from glob import glob
from setuptools import setup, find_packages
from setuptools.command.install import install
from shutil import copytree, rmtree

package_name = 'final_project'

data_files=[
    ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
    ('share/' + package_name, ['package.xml']),
    ('share/' + package_name + '/launch', glob('launch/*.launch.py')),
    ('share/' + package_name + '/model', glob('model/*.urdf'))
]

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=data_files,
    install_requires=['setuptools', 'numpy', 'scipy'],
    zip_safe=True,
    maintainer='team 8',
    maintainer_email='awesome@stanford.edu',
    description='me326 final project for team 8',
    license='MIT License',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'project_launcher = final_project.project.launch:main',
            'spawn_april_tags = final_project.spawn_april_tags.launch:main',
            'static_frame_broadcaster = final_project.static_frame_broadcaster:main',
            'dummy_subscriber = final_project.dummy_subscriber:main',
            'pose_estimator = final_project.pose_estimator:main',
            'world_publisher = final_project.world_publisher:main',
<<<<<<< HEAD
=======
            'client_server = final_project.client_server:main'
>>>>>>> action_client
        ],
    }
)
