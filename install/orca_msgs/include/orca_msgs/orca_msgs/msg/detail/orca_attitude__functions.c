// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from orca_msgs:msg/OrcaAttitude.idl
// generated code does not contain a copyright notice
#include "orca_msgs/msg/detail/orca_attitude__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
orca_msgs__msg__OrcaAttitude__init(orca_msgs__msg__OrcaAttitude * msg)
{
  if (!msg) {
    return false;
  }
  // initial_x
  // initial_y
  // initial_z
  // yaw_deg
  // initial_deg
  // roll_deg
  // pitch_deg
  // rollspeed_deg_s
  // pitchspeed_deg_s
  // yawspeed_deg_s
  return true;
}

void
orca_msgs__msg__OrcaAttitude__fini(orca_msgs__msg__OrcaAttitude * msg)
{
  if (!msg) {
    return;
  }
  // initial_x
  // initial_y
  // initial_z
  // yaw_deg
  // initial_deg
  // roll_deg
  // pitch_deg
  // rollspeed_deg_s
  // pitchspeed_deg_s
  // yawspeed_deg_s
}

bool
orca_msgs__msg__OrcaAttitude__are_equal(const orca_msgs__msg__OrcaAttitude * lhs, const orca_msgs__msg__OrcaAttitude * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // initial_x
  if (lhs->initial_x != rhs->initial_x) {
    return false;
  }
  // initial_y
  if (lhs->initial_y != rhs->initial_y) {
    return false;
  }
  // initial_z
  if (lhs->initial_z != rhs->initial_z) {
    return false;
  }
  // yaw_deg
  if (lhs->yaw_deg != rhs->yaw_deg) {
    return false;
  }
  // initial_deg
  if (lhs->initial_deg != rhs->initial_deg) {
    return false;
  }
  // roll_deg
  if (lhs->roll_deg != rhs->roll_deg) {
    return false;
  }
  // pitch_deg
  if (lhs->pitch_deg != rhs->pitch_deg) {
    return false;
  }
  // rollspeed_deg_s
  if (lhs->rollspeed_deg_s != rhs->rollspeed_deg_s) {
    return false;
  }
  // pitchspeed_deg_s
  if (lhs->pitchspeed_deg_s != rhs->pitchspeed_deg_s) {
    return false;
  }
  // yawspeed_deg_s
  if (lhs->yawspeed_deg_s != rhs->yawspeed_deg_s) {
    return false;
  }
  return true;
}

bool
orca_msgs__msg__OrcaAttitude__copy(
  const orca_msgs__msg__OrcaAttitude * input,
  orca_msgs__msg__OrcaAttitude * output)
{
  if (!input || !output) {
    return false;
  }
  // initial_x
  output->initial_x = input->initial_x;
  // initial_y
  output->initial_y = input->initial_y;
  // initial_z
  output->initial_z = input->initial_z;
  // yaw_deg
  output->yaw_deg = input->yaw_deg;
  // initial_deg
  output->initial_deg = input->initial_deg;
  // roll_deg
  output->roll_deg = input->roll_deg;
  // pitch_deg
  output->pitch_deg = input->pitch_deg;
  // rollspeed_deg_s
  output->rollspeed_deg_s = input->rollspeed_deg_s;
  // pitchspeed_deg_s
  output->pitchspeed_deg_s = input->pitchspeed_deg_s;
  // yawspeed_deg_s
  output->yawspeed_deg_s = input->yawspeed_deg_s;
  return true;
}

orca_msgs__msg__OrcaAttitude *
orca_msgs__msg__OrcaAttitude__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  orca_msgs__msg__OrcaAttitude * msg = (orca_msgs__msg__OrcaAttitude *)allocator.allocate(sizeof(orca_msgs__msg__OrcaAttitude), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(orca_msgs__msg__OrcaAttitude));
  bool success = orca_msgs__msg__OrcaAttitude__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
orca_msgs__msg__OrcaAttitude__destroy(orca_msgs__msg__OrcaAttitude * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    orca_msgs__msg__OrcaAttitude__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
orca_msgs__msg__OrcaAttitude__Sequence__init(orca_msgs__msg__OrcaAttitude__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  orca_msgs__msg__OrcaAttitude * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(orca_msgs__msg__OrcaAttitude)) {
      return false;
    }
    data = (orca_msgs__msg__OrcaAttitude *)allocator.zero_allocate(size, sizeof(orca_msgs__msg__OrcaAttitude), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = orca_msgs__msg__OrcaAttitude__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        orca_msgs__msg__OrcaAttitude__fini(&data[i - 1]);
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
orca_msgs__msg__OrcaAttitude__Sequence__fini(orca_msgs__msg__OrcaAttitude__Sequence * array)
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
      orca_msgs__msg__OrcaAttitude__fini(&array->data[i]);
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

orca_msgs__msg__OrcaAttitude__Sequence *
orca_msgs__msg__OrcaAttitude__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  orca_msgs__msg__OrcaAttitude__Sequence * array = (orca_msgs__msg__OrcaAttitude__Sequence *)allocator.allocate(sizeof(orca_msgs__msg__OrcaAttitude__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = orca_msgs__msg__OrcaAttitude__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
orca_msgs__msg__OrcaAttitude__Sequence__destroy(orca_msgs__msg__OrcaAttitude__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    orca_msgs__msg__OrcaAttitude__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
orca_msgs__msg__OrcaAttitude__Sequence__are_equal(const orca_msgs__msg__OrcaAttitude__Sequence * lhs, const orca_msgs__msg__OrcaAttitude__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!orca_msgs__msg__OrcaAttitude__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
orca_msgs__msg__OrcaAttitude__Sequence__copy(
  const orca_msgs__msg__OrcaAttitude__Sequence * input,
  orca_msgs__msg__OrcaAttitude__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(orca_msgs__msg__OrcaAttitude)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(orca_msgs__msg__OrcaAttitude);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    orca_msgs__msg__OrcaAttitude * data =
      (orca_msgs__msg__OrcaAttitude *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!orca_msgs__msg__OrcaAttitude__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          orca_msgs__msg__OrcaAttitude__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!orca_msgs__msg__OrcaAttitude__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
