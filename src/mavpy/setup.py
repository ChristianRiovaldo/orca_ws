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
            'test_control = mavpy.test_control:main',
            'test_keyboard = mavpy.test_keyboard:main',
            'control_bridge = mavpy.control_bridge:main',
            'keyboard = mavpy.keyboard:main',
        ],
    },
)
