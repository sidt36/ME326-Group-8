import os
from setuptools import find_packages
from setuptools import setup

setup(
    name='pose_traj_controller',
    version='0.0.0',
    packages=find_packages(
        include=('pose_traj_controller', 'pose_traj_controller.*')),
)
