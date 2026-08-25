# generated from rosidl_generator_py/resource/_idl.py.em
# with input from orca_msgs:msg/OrcaAttitude.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_OrcaAttitude(type):
    """Metaclass of message 'OrcaAttitude'."""

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
                'orca_msgs.msg.OrcaAttitude')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__orca_attitude
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__orca_attitude
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__orca_attitude
            cls._TYPE_SUPPORT = module.type_support_msg__msg__orca_attitude
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__orca_attitude

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class OrcaAttitude(metaclass=Metaclass_OrcaAttitude):
    """Message class 'OrcaAttitude'."""

    __slots__ = [
        '_initial_x',
        '_initial_y',
        '_initial_z',
        '_yaw_deg',
        '_initial_deg',
        '_roll_deg',
        '_pitch_deg',
        '_rollspeed_deg_s',
        '_pitchspeed_deg_s',
        '_yawspeed_deg_s',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'initial_x': 'float',
        'initial_y': 'float',
        'initial_z': 'float',
        'yaw_deg': 'float',
        'initial_deg': 'float',
        'roll_deg': 'float',
        'pitch_deg': 'float',
        'rollspeed_deg_s': 'float',
        'pitchspeed_deg_s': 'float',
        'yawspeed_deg_s': 'float',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
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
        self.initial_x = kwargs.get('initial_x', float())
        self.initial_y = kwargs.get('initial_y', float())
        self.initial_z = kwargs.get('initial_z', float())
        self.yaw_deg = kwargs.get('yaw_deg', float())
        self.initial_deg = kwargs.get('initial_deg', float())
        self.roll_deg = kwargs.get('roll_deg', float())
        self.pitch_deg = kwargs.get('pitch_deg', float())
        self.rollspeed_deg_s = kwargs.get('rollspeed_deg_s', float())
        self.pitchspeed_deg_s = kwargs.get('pitchspeed_deg_s', float())
        self.yawspeed_deg_s = kwargs.get('yawspeed_deg_s', float())

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
        if self.initial_x != other.initial_x:
            return False
        if self.initial_y != other.initial_y:
            return False
        if self.initial_z != other.initial_z:
            return False
        if self.yaw_deg != other.yaw_deg:
            return False
        if self.initial_deg != other.initial_deg:
            return False
        if self.roll_deg != other.roll_deg:
            return False
        if self.pitch_deg != other.pitch_deg:
            return False
        if self.rollspeed_deg_s != other.rollspeed_deg_s:
            return False
        if self.pitchspeed_deg_s != other.pitchspeed_deg_s:
            return False
        if self.yawspeed_deg_s != other.yawspeed_deg_s:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def initial_x(self):
        """Message field 'initial_x'."""
        return self._initial_x

    @initial_x.setter
    def initial_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'initial_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'initial_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._initial_x = value

    @builtins.property
    def initial_y(self):
        """Message field 'initial_y'."""
        return self._initial_y

    @initial_y.setter
    def initial_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'initial_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'initial_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._initial_y = value

    @builtins.property
    def initial_z(self):
        """Message field 'initial_z'."""
        return self._initial_z

    @initial_z.setter
    def initial_z(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'initial_z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'initial_z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._initial_z = value

    @builtins.property
    def yaw_deg(self):
        """Message field 'yaw_deg'."""
        return self._yaw_deg

    @yaw_deg.setter
    def yaw_deg(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'yaw_deg' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw_deg' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw_deg = value

    @builtins.property
    def initial_deg(self):
        """Message field 'initial_deg'."""
        return self._initial_deg

    @initial_deg.setter
    def initial_deg(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'initial_deg' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'initial_deg' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._initial_deg = value

    @builtins.property
    def roll_deg(self):
        """Message field 'roll_deg'."""
        return self._roll_deg

    @roll_deg.setter
    def roll_deg(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'roll_deg' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'roll_deg' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._roll_deg = value

    @builtins.property
    def pitch_deg(self):
        """Message field 'pitch_deg'."""
        return self._pitch_deg

    @pitch_deg.setter
    def pitch_deg(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'pitch_deg' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pitch_deg' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pitch_deg = value

    @builtins.property
    def rollspeed_deg_s(self):
        """Message field 'rollspeed_deg_s'."""
        return self._rollspeed_deg_s

    @rollspeed_deg_s.setter
    def rollspeed_deg_s(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'rollspeed_deg_s' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'rollspeed_deg_s' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._rollspeed_deg_s = value

    @builtins.property
    def pitchspeed_deg_s(self):
        """Message field 'pitchspeed_deg_s'."""
        return self._pitchspeed_deg_s

    @pitchspeed_deg_s.setter
    def pitchspeed_deg_s(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'pitchspeed_deg_s' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pitchspeed_deg_s' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pitchspeed_deg_s = value

    @builtins.property
    def yawspeed_deg_s(self):
        """Message field 'yawspeed_deg_s'."""
        return self._yawspeed_deg_s

    @yawspeed_deg_s.setter
    def yawspeed_deg_s(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'yawspeed_deg_s' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yawspeed_deg_s' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yawspeed_deg_s = value
