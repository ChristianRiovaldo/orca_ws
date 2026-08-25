// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from orca_msgs:msg/OrcaProximity.idl
// generated code does not contain a copyright notice
#include "orca_msgs/msg/detail/orca_proximity__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
orca_msgs__msg__OrcaProximity__init(orca_msgs__msg__OrcaProximity * msg)
{
  if (!msg) {
    return false;
  }
  // arm_mode
  return true;
}

void
orca_msgs__msg__OrcaProximity__fini(orca_msgs__msg__OrcaProximity * msg)
{
  if (!msg) {
    return;
  }
  // arm_mode
}

bool
orca_msgs__msg__OrcaProximity__are_equal(const orca_msgs__msg__OrcaProximity * lhs, const orca_msgs__msg__OrcaProximity * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // arm_mode
  if (lhs->arm_mode != rhs->arm_mode) {
    return false;
  }
  return true;
}

bool
orca_msgs__msg__OrcaProximity__copy(
  const orca_msgs__msg__OrcaProximity * input,
  orca_msgs__msg__OrcaProximity * output)
{
  if (!input || !output) {
    return false;
  }
  // arm_mode
  output->arm_mode = input->arm_mode;
  return true;
}

orca_msgs__msg__OrcaProximity *
orca_msgs__msg__OrcaProximity__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  orca_msgs__msg__OrcaProximity * msg = (orca_msgs__msg__OrcaProximity *)allocator.allocate(sizeof(orca_msgs__msg__OrcaProximity), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(orca_msgs__msg__OrcaProximity));
  bool success = orca_msgs__msg__OrcaProximity__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
orca_msgs__msg__OrcaProximity__destroy(orca_msgs__msg__OrcaProximity * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    orca_msgs__msg__OrcaProximity__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
orca_msgs__msg__OrcaProximity__Sequence__init(orca_msgs__msg__OrcaProximity__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  orca_msgs__msg__OrcaProximity * data = NULL;

  if (size) {
    data = (orca_msgs__msg__OrcaProximity *)allocator.zero_allocate(size, sizeof(orca_msgs__msg__OrcaProximity), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = orca_msgs__msg__OrcaProximity__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        orca_msgs__msg__OrcaProximity__fini(&data[i - 1]);
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
orca_msgs__msg__OrcaProximity__Sequence__fini(orca_msgs__msg__OrcaProximity__Sequence * array)
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
      orca_msgs__msg__OrcaProximity__fini(&array->data[i]);
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

orca_msgs__msg__OrcaProximity__Sequence *
orca_msgs__msg__OrcaProximity__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  orca_msgs__msg__OrcaProximity__Sequence * array = (orca_msgs__msg__OrcaProximity__Sequence *)allocator.allocate(sizeof(orca_msgs__msg__OrcaProximity__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = orca_msgs__msg__OrcaProximity__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
orca_msgs__msg__OrcaProximity__Sequence__destroy(orca_msgs__msg__OrcaProximity__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    orca_msgs__msg__OrcaProximity__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
orca_msgs__msg__OrcaProximity__Sequence__are_equal(const orca_msgs__msg__OrcaProximity__Sequence * lhs, const orca_msgs__msg__OrcaProximity__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!orca_msgs__msg__OrcaProximity__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
orca_msgs__msg__OrcaProximity__Sequence__copy(
  const orca_msgs__msg__OrcaProximity__Sequence * input,
  orca_msgs__msg__OrcaProximity__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(orca_msgs__msg__OrcaProximity);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    orca_msgs__msg__OrcaProximity * data =
      (orca_msgs__msg__OrcaProximity *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!orca_msgs__msg__OrcaProximity__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          orca_msgs__msg__OrcaProximity__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!orca_msgs__msg__OrcaProximity__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
