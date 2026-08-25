from setuptools import setup, find_packages
import os
from glob import glob

package_name = 'mavpy'

setup(
    name=package_name,
    version='0.1.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'models'), glob('mavpy/models/*')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='jetson',
    maintainer_email='jetson@todo.todo',
    description='ORCA sensor, control bridge, teleop, and qualification nodes',
    license='Proprietary',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'attitude_node = mavpy.attitude_node:main',
            'camera_gate_node = mavpy.camera_gate_node:main',
            'camera_qualification_sim = mavpy.camera_qualification_sim:main',
            'camera_final_sim = mavpy.camera_final_sim:main',
            'camera_final = mavpy.camera_final:main',

            'control_bridge = mavpy.control_bridge:main',
            'communication_sim = mavpy.communication_sim:main',
            'depth_node = mavpy.depth_node:main',
            'depth_sim = mavpy.depth_sim:main',

            'final_sim = mavpy.final_sim:main',
            'final = mavpy.final:main',
            
            'joystick = mavpy.joystick:main',
            'keyboard = mavpy.keyboard:main',
            'proximity_node = mavpy.proximity_node:main',
            'qualification_mission = mavpy.qualification_mission:main',
            'qualification_sim = mavpy.qualification_sim:main',
        ],
    },
)
