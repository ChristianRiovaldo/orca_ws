// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from orca_msgs:msg/OrcaDepth.idl
// generated code does not contain a copyright notice
#include "orca_msgs/msg/detail/orca_depth__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
orca_msgs__msg__OrcaDepth__init(orca_msgs__msg__OrcaDepth * msg)
{
  if (!msg) {
    return false;
  }
  // depth
  // pressure
  return true;
}

void
orca_msgs__msg__OrcaDepth__fini(orca_msgs__msg__OrcaDepth * msg)
{
  if (!msg) {
    return;
  }
  // depth
  // pressure
}

bool
orca_msgs__msg__OrcaDepth__are_equal(const orca_msgs__msg__OrcaDepth * lhs, const orca_msgs__msg__OrcaDepth * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // depth
  if (lhs->depth != rhs->depth) {
    return false;
  }
  // pressure
  if (lhs->pressure != rhs->pressure) {
    return false;
  }
  return true;
}

bool
orca_msgs__msg__OrcaDepth__copy(
  const orca_msgs__msg__OrcaDepth * input,
  orca_msgs__msg__OrcaDepth * output)
{
  if (!input || !output) {
    return false;
  }
  // depth
  output->depth = input->depth;
  // pressure
  output->pressure = input->pressure;
  return true;
}

orca_msgs__msg__OrcaDepth *
orca_msgs__msg__OrcaDepth__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  orca_msgs__msg__OrcaDepth * msg = (orca_msgs__msg__OrcaDepth *)allocator.allocate(sizeof(orca_msgs__msg__OrcaDepth), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(orca_msgs__msg__OrcaDepth));
  bool success = orca_msgs__msg__OrcaDepth__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
orca_msgs__msg__OrcaDepth__destroy(orca_msgs__msg__OrcaDepth * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    orca_msgs__msg__OrcaDepth__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
orca_msgs__msg__OrcaDepth__Sequence__init(orca_msgs__msg__OrcaDepth__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  orca_msgs__msg__OrcaDepth * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(orca_msgs__msg__OrcaDepth)) {
      return false;
    }
    data = (orca_msgs__msg__OrcaDepth *)allocator.zero_allocate(size, sizeof(orca_msgs__msg__OrcaDepth), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = orca_msgs__msg__OrcaDepth__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        orca_msgs__msg__OrcaDepth__fini(&data[i - 1]);
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
orca_msgs__msg__OrcaDepth__Sequence__fini(orca_msgs__msg__OrcaDepth__Sequence * array)
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
      orca_msgs__msg__OrcaDepth__fini(&array->data[i]);
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

orca_msgs__msg__OrcaDepth__Sequence *
orca_msgs__msg__OrcaDepth__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  orca_msgs__msg__OrcaDepth__Sequence * array = (orca_msgs__msg__OrcaDepth__Sequence *)allocator.allocate(sizeof(orca_msgs__msg__OrcaDepth__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = orca_msgs__msg__OrcaDepth__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
orca_msgs__msg__OrcaDepth__Sequence__destroy(orca_msgs__msg__OrcaDepth__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    orca_msgs__msg__OrcaDepth__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
orca_msgs__msg__OrcaDepth__Sequence__are_equal(const orca_msgs__msg__OrcaDepth__Sequence * lhs, const orca_msgs__msg__OrcaDepth__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!orca_msgs__msg__OrcaDepth__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
orca_msgs__msg__OrcaDepth__Sequence__copy(
  const orca_msgs__msg__OrcaDepth__Sequence * input,
  orca_msgs__msg__OrcaDepth__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(orca_msgs__msg__OrcaDepth)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(orca_msgs__msg__OrcaDepth);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    orca_msgs__msg__OrcaDepth * data =
      (orca_msgs__msg__OrcaDepth *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!orca_msgs__msg__OrcaDepth__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          orca_msgs__msg__OrcaDepth__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!orca_msgs__msg__OrcaDepth__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
