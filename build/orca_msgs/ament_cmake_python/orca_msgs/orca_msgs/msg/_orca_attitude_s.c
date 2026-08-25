// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from orca_msgs:msg/OrcaAttitude.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "orca_msgs/msg/detail/orca_attitude__struct.h"
#include "orca_msgs/msg/detail/orca_attitude__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool orca_msgs__msg__orca_attitude__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[42];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("orca_msgs.msg._orca_attitude.OrcaAttitude", full_classname_dest, 41) == 0);
  }
  orca_msgs__msg__OrcaAttitude * ros_message = _ros_message;
  {  // initial_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "initial_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->initial_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // initial_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "initial_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->initial_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // initial_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "initial_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->initial_z = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // yaw_deg
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw_deg");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->yaw_deg = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // initial_deg
    PyObject * field = PyObject_GetAttrString(_pymsg, "initial_deg");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->initial_deg = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // roll_deg
    PyObject * field = PyObject_GetAttrString(_pymsg, "roll_deg");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->roll_deg = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pitch_deg
    PyObject * field = PyObject_GetAttrString(_pymsg, "pitch_deg");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pitch_deg = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rollspeed_deg_s
    PyObject * field = PyObject_GetAttrString(_pymsg, "rollspeed_deg_s");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rollspeed_deg_s = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pitchspeed_deg_s
    PyObject * field = PyObject_GetAttrString(_pymsg, "pitchspeed_deg_s");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pitchspeed_deg_s = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // yawspeed_deg_s
    PyObject * field = PyObject_GetAttrString(_pymsg, "yawspeed_deg_s");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->yawspeed_deg_s = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * orca_msgs__msg__orca_attitude__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of OrcaAttitude */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("orca_msgs.msg._orca_attitude");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "OrcaAttitude");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  orca_msgs__msg__OrcaAttitude * ros_message = (orca_msgs__msg__OrcaAttitude *)raw_ros_message;
  {  // initial_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->initial_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "initial_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // initial_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->initial_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "initial_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // initial_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->initial_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "initial_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw_deg
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->yaw_deg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw_deg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // initial_deg
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->initial_deg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "initial_deg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // roll_deg
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->roll_deg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "roll_deg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pitch_deg
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pitch_deg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pitch_deg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rollspeed_deg_s
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rollspeed_deg_s);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rollspeed_deg_s", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pitchspeed_deg_s
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pitchspeed_deg_s);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pitchspeed_deg_s", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yawspeed_deg_s
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->yawspeed_deg_s);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yawspeed_deg_s", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
