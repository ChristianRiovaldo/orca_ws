// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from orca_msgs:msg/OrcaControl.idl
// generated code does not contain a copyright notice
#include "orca_msgs/msg/detail/orca_control__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `arm_mode`
// Member `control_mode`
// Member `gripper_mode`
// Member `source`
#include "rosidl_runtime_c/string_functions.h"

bool
orca_msgs__msg__OrcaControl__init(orca_msgs__msg__OrcaControl * msg)
{
  if (!msg) {
    return false;
  }
  // throttle
  // lateral
  // forward
  // yaw
  // pitch
  // roll
  // arm_mode
  if (!rosidl_runtime_c__String__init(&msg->arm_mode)) {
    orca_msgs__msg__OrcaControl__fini(msg);
    return false;
  }
  // control_mode
  if (!rosidl_runtime_c__String__init(&msg->control_mode)) {
    orca_msgs__msg__OrcaControl__fini(msg);
    return false;
  }
  // gripper_mode
  if (!rosidl_runtime_c__String__init(&msg->gripper_mode)) {
    orca_msgs__msg__OrcaControl__fini(msg);
    return false;
  }
  // source
  if (!rosidl_runtime_c__String__init(&msg->source)) {
    orca_msgs__msg__OrcaControl__fini(msg);
    return false;
  }
  return true;
}

void
orca_msgs__msg__OrcaControl__fini(orca_msgs__msg__OrcaControl * msg)
{
  if (!msg) {
    return;
  }
  // throttle
  // lateral
  // forward
  // yaw
  // pitch
  // roll
  // arm_mode
  rosidl_runtime_c__String__fini(&msg->arm_mode);
  // control_mode
  rosidl_runtime_c__String__fini(&msg->control_mode);
  // gripper_mode
  rosidl_runtime_c__String__fini(&msg->gripper_mode);
  // source
  rosidl_runtime_c__String__fini(&msg->source);
}

bool
orca_msgs__msg__OrcaControl__are_equal(const orca_msgs__msg__OrcaControl * lhs, const orca_msgs__msg__OrcaControl * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // throttle
  if (lhs->throttle != rhs->throttle) {
    return false;
  }
  // lateral
  if (lhs->lateral != rhs->lateral) {
    return false;
  }
  // forward
  if (lhs->forward != rhs->forward) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  // arm_mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->arm_mode), &(rhs->arm_mode)))
  {
    return false;
  }
  // control_mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->control_mode), &(rhs->control_mode)))
  {
    return false;
  }
  // gripper_mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->gripper_mode), &(rhs->gripper_mode)))
  {
    return false;
  }
  // source
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->source), &(rhs->source)))
  {
    return false;
  }
  return true;
}

bool
orca_msgs__msg__OrcaControl__copy(
  const orca_msgs__msg__OrcaControl * input,
  orca_msgs__msg__OrcaControl * output)
{
  if (!input || !output) {
    return false;
  }
  // throttle
  output->throttle = input->throttle;
  // lateral
  output->lateral = input->lateral;
  // forward
  output->forward = input->forward;
  // yaw
  output->yaw = input->yaw;
  // pitch
  output->pitch = input->pitch;
  // roll
  output->roll = input->roll;
  // arm_mode
  if (!rosidl_runtime_c__String__copy(
      &(input->arm_mode), &(output->arm_mode)))
  {
    return false;
  }
  // control_mode
  if (!rosidl_runtime_c__String__copy(
      &(input->control_mode), &(output->control_mode)))
  {
    return false;
  }
  // gripper_mode
  if (!rosidl_runtime_c__String__copy(
      &(input->gripper_mode), &(output->gripper_mode)))
  {
    return false;
  }
  // source
  if (!rosidl_runtime_c__String__copy(
      &(input->source), &(output->source)))
  {
    return false;
  }
  return true;
}

orca_msgs__msg__OrcaControl *
orca_msgs__msg__OrcaControl__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  orca_msgs__msg__OrcaControl * msg = (orca_msgs__msg__OrcaControl *)allocator.allocate(sizeof(orca_msgs__msg__OrcaControl), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(orca_msgs__msg__OrcaControl));
  bool success = orca_msgs__msg__OrcaControl__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
orca_msgs__msg__OrcaControl__destroy(orca_msgs__msg__OrcaControl * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    orca_msgs__msg__OrcaControl__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
orca_msgs__msg__OrcaControl__Sequence__init(orca_msgs__msg__OrcaControl__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  orca_msgs__msg__OrcaControl * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(orca_msgs__msg__OrcaControl)) {
      return false;
    }
    data = (orca_msgs__msg__OrcaControl *)allocator.zero_allocate(size, sizeof(orca_msgs__msg__OrcaControl), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = orca_msgs__msg__OrcaControl__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        orca_msgs__msg__OrcaControl__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
orca_msgs__msg__OrcaControl__Sequence__fini(orca_msgs__msg__OrcaControl__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      orca_msgs__msg__OrcaControl__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

orca_msgs__msg__OrcaControl__Sequence *
orca_msgs__msg__OrcaControl__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  orca_msgs__msg__OrcaControl__Sequence * array = (orca_msgs__msg__OrcaControl__Sequence *)allocator.allocate(sizeof(orca_msgs__msg__OrcaControl__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = orca_msgs__msg__OrcaControl__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
orca_msgs__msg__OrcaControl__Sequence__destroy(orca_msgs__msg__OrcaControl__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    orca_msgs__msg__OrcaControl__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
orca_msgs__msg__OrcaControl__Sequence__are_equal(const orca_msgs__msg__OrcaControl__Sequence * lhs, const orca_msgs__msg__OrcaControl__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!orca_msgs__msg__OrcaControl__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
orca_msgs__msg__OrcaControl__Sequence__copy(
  const orca_msgs__msg__OrcaControl__Sequence * input,
  orca_msgs__msg__OrcaControl__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(orca_msgs__msg__OrcaControl)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(orca_msgs__msg__OrcaControl);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    orca_msgs__msg__OrcaControl * data =
      (orca_msgs__msg__OrcaControl *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!orca_msgs__msg__OrcaControl__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          orca_msgs__msg__OrcaControl__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!orca_msgs__msg__OrcaControl__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
