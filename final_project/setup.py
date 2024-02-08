from setuptools import setup

package_name = 'final_project'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/final_project/launch', ['launch/project_launcher.py'])
    ],
    install_requires=['setuptools', 'numpy', 'scipy'],
    zip_safe=True,
    maintainer='team 8',
    maintainer_email='awesome@stanford.edu',
    description='me326 final project for team 8',
    license='MIT License',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'project_launcher = final_project.project_launcher:main',
        ],
    },
)
