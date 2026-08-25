# generated from rosidl_generator_py/resource/_idl.py.em
# with input from orca_msgs:msg/OrcaControl.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_OrcaControl(type):
    """Metaclass of message 'OrcaControl'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('orca_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'orca_msgs.msg.OrcaControl')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__orca_control
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__orca_control
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__orca_control
            cls._TYPE_SUPPORT = module.type_support_msg__msg__orca_control
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__orca_control

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class OrcaControl(metaclass=Metaclass_OrcaControl):
    """Message class 'OrcaControl'."""

    __slots__ = [
        '_throttle',
        '_lateral',
        '_forward',
        '_yaw',
        '_arm_mode',
        '_control_mode',
        '_gripper_mode',
        '_source',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'throttle': 'int16',
        'lateral': 'int16',
        'forward': 'int16',
        'yaw': 'int16',
        'arm_mode': 'string',
        'control_mode': 'string',
        'gripper_mode': 'string',
        'source': 'string',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.throttle = kwargs.get('throttle', int())
        self.lateral = kwargs.get('lateral', int())
        self.forward = kwargs.get('forward', int())
        self.yaw = kwargs.get('yaw', int())
        self.arm_mode = kwargs.get('arm_mode', str())
        self.control_mode = kwargs.get('control_mode', str())
        self.gripper_mode = kwargs.get('gripper_mode', str())
        self.source = kwargs.get('source', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.throttle != other.throttle:
            return False
        if self.lateral != other.lateral:
            return False
        if self.forward != other.forward:
            return False
        if self.yaw != other.yaw:
            return False
        if self.arm_mode != other.arm_mode:
            return False
        if self.control_mode != other.control_mode:
            return False
        if self.gripper_mode != other.gripper_mode:
            return False
        if self.source != other.source:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def throttle(self):
        """Message field 'throttle'."""
        return self._throttle

    @throttle.setter
    def throttle(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'throttle' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'throttle' field must be an integer in [-32768, 32767]"
        self._throttle = value

    @builtins.property
    def lateral(self):
        """Message field 'lateral'."""
        return self._lateral

    @lateral.setter
    def lateral(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'lateral' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'lateral' field must be an integer in [-32768, 32767]"
        self._lateral = value

    @builtins.property
    def forward(self):
        """Message field 'forward'."""
        return self._forward

    @forward.setter
    def forward(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'forward' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'forward' field must be an integer in [-32768, 32767]"
        self._forward = value

    @builtins.property
    def yaw(self):
        """Message field 'yaw'."""
        return self._yaw

    @yaw.setter
    def yaw(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'yaw' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'yaw' field must be an integer in [-32768, 32767]"
        self._yaw = value

    @builtins.property
    def arm_mode(self):
        """Message field 'arm_mode'."""
        return self._arm_mode

    @arm_mode.setter
    def arm_mode(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'arm_mode' field must be of type 'str'"
        self._arm_mode = value

    @builtins.property
    def control_mode(self):
        """Message field 'control_mode'."""
        return self._control_mode

    @control_mode.setter
    def control_mode(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'control_mode' field must be of type 'str'"
        self._control_mode = value

    @builtins.property
    def gripper_mode(self):
        """Message field 'gripper_mode'."""
        return self._gripper_mode

    @gripper_mode.setter
    def gripper_mode(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'gripper_mode' field must be of type 'str'"
        self._gripper_mode = value

    @builtins.property
    def source(self):
        """Message field 'source'."""
        return self._source

    @source.setter
    def source(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'source' field must be of type 'str'"
        self._source = value
