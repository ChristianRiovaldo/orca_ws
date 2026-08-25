# generated from rosidl_generator_py/resource/_idl.py.em
# with input from orca_msgs:msg/FinalDetection.idl
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


class Metaclass_FinalDetection(type):
    """Metaclass of message 'FinalDetection'."""

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
                'orca_msgs.msg.FinalDetection')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__final_detection
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__final_detection
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__final_detection
            cls._TYPE_SUPPORT = module.type_support_msg__msg__final_detection
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__final_detection

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FinalDetection(metaclass=Metaclass_FinalDetection):
    """Message class 'FinalDetection'."""

    __slots__ = [
        '_detected',
        '_class_name',
        '_confidence',
        '_center_x',
        '_center_y',
        '_center_x_norm',
        '_bbox_width',
        '_bbox_height',
        '_bbox_area_ratio',
        '_distance',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'detected': 'boolean',
        'class_name': 'string',
        'confidence': 'float',
        'center_x': 'float',
        'center_y': 'float',
        'center_x_norm': 'float',
        'bbox_width': 'float',
        'bbox_height': 'float',
        'bbox_area_ratio': 'float',
        'distance': 'float',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
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
        self.detected = kwargs.get('detected', bool())
        self.class_name = kwargs.get('class_name', str())
        self.confidence = kwargs.get('confidence', float())
        self.center_x = kwargs.get('center_x', float())
        self.center_y = kwargs.get('center_y', float())
        self.center_x_norm = kwargs.get('center_x_norm', float())
        self.bbox_width = kwargs.get('bbox_width', float())
        self.bbox_height = kwargs.get('bbox_height', float())
        self.bbox_area_ratio = kwargs.get('bbox_area_ratio', float())
        self.distance = kwargs.get('distance', float())

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
        if self.detected != other.detected:
            return False
        if self.class_name != other.class_name:
            return False
        if self.confidence != other.confidence:
            return False
        if self.center_x != other.center_x:
            return False
        if self.center_y != other.center_y:
            return False
        if self.center_x_norm != other.center_x_norm:
            return False
        if self.bbox_width != other.bbox_width:
            return False
        if self.bbox_height != other.bbox_height:
            return False
        if self.bbox_area_ratio != other.bbox_area_ratio:
            return False
        if self.distance != other.distance:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def detected(self):
        """Message field 'detected'."""
        return self._detected

    @detected.setter
    def detected(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'detected' field must be of type 'bool'"
        self._detected = value

    @builtins.property
    def class_name(self):
        """Message field 'class_name'."""
        return self._class_name

    @class_name.setter
    def class_name(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'class_name' field must be of type 'str'"
        self._class_name = value

    @builtins.property
    def confidence(self):
        """Message field 'confidence'."""
        return self._confidence

    @confidence.setter
    def confidence(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'confidence' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'confidence' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._confidence = value

    @builtins.property
    def center_x(self):
        """Message field 'center_x'."""
        return self._center_x

    @center_x.setter
    def center_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'center_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'center_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._center_x = value

    @builtins.property
    def center_y(self):
        """Message field 'center_y'."""
        return self._center_y

    @center_y.setter
    def center_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'center_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'center_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._center_y = value

    @builtins.property
    def center_x_norm(self):
        """Message field 'center_x_norm'."""
        return self._center_x_norm

    @center_x_norm.setter
    def center_x_norm(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'center_x_norm' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'center_x_norm' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._center_x_norm = value

    @builtins.property
    def bbox_width(self):
        """Message field 'bbox_width'."""
        return self._bbox_width

    @bbox_width.setter
    def bbox_width(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'bbox_width' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bbox_width' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bbox_width = value

    @builtins.property
    def bbox_height(self):
        """Message field 'bbox_height'."""
        return self._bbox_height

    @bbox_height.setter
    def bbox_height(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'bbox_height' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bbox_height' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bbox_height = value

    @builtins.property
    def bbox_area_ratio(self):
        """Message field 'bbox_area_ratio'."""
        return self._bbox_area_ratio

    @bbox_area_ratio.setter
    def bbox_area_ratio(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'bbox_area_ratio' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bbox_area_ratio' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bbox_area_ratio = value

    @builtins.property
    def distance(self):
        """Message field 'distance'."""
        return self._distance

    @distance.setter
    def distance(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'distance' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'distance' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._distance = value
