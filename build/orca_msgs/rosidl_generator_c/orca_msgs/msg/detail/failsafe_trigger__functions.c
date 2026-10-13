// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from orca_msgs:msg/FailsafeTrigger.idl
// generated code does not contain a copyright notice
#include "orca_msgs/msg/detail/failsafe_trigger__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
orca_msgs__msg__FailsafeTrigger__init(orca_msgs__msg__FailsafeTrigger * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
orca_msgs__msg__FailsafeTrigger__fini(orca_msgs__msg__FailsafeTrigger * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
orca_msgs__msg__FailsafeTrigger__are_equal(const orca_msgs__msg__FailsafeTrigger * lhs, const orca_msgs__msg__FailsafeTrigger * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
orca_msgs__msg__FailsafeTrigger__copy(
  const orca_msgs__msg__FailsafeTrigger * input,
  orca_msgs__msg__FailsafeTrigger * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

orca_msgs__msg__FailsafeTrigger *
orca_msgs__msg__FailsafeTrigger__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  orca_msgs__msg__FailsafeTrigger * msg = (orca_msgs__msg__FailsafeTrigger *)allocator.allocate(sizeof(orca_msgs__msg__FailsafeTrigger), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(orca_msgs__msg__FailsafeTrigger));
  bool success = orca_msgs__msg__FailsafeTrigger__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
orca_msgs__msg__FailsafeTrigger__destroy(orca_msgs__msg__FailsafeTrigger * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    orca_msgs__msg__FailsafeTrigger__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
orca_msgs__msg__FailsafeTrigger__Sequence__init(orca_msgs__msg__FailsafeTrigger__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  orca_msgs__msg__FailsafeTrigger * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(orca_msgs__msg__FailsafeTrigger)) {
      return false;
    }
    data = (orca_msgs__msg__FailsafeTrigger *)allocator.zero_allocate(size, sizeof(orca_msgs__msg__FailsafeTrigger), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = orca_msgs__msg__FailsafeTrigger__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        orca_msgs__msg__FailsafeTrigger__fini(&data[i - 1]);
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
orca_msgs__msg__FailsafeTrigger__Sequence__fini(orca_msgs__msg__FailsafeTrigger__Sequence * array)
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
      orca_msgs__msg__FailsafeTrigger__fini(&array->data[i]);
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

orca_msgs__msg__FailsafeTrigger__Sequence *
orca_msgs__msg__FailsafeTrigger__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  orca_msgs__msg__FailsafeTrigger__Sequence * array = (orca_msgs__msg__FailsafeTrigger__Sequence *)allocator.allocate(sizeof(orca_msgs__msg__FailsafeTrigger__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = orca_msgs__msg__FailsafeTrigger__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
orca_msgs__msg__FailsafeTrigger__Sequence__destroy(orca_msgs__msg__FailsafeTrigger__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    orca_msgs__msg__FailsafeTrigger__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
orca_msgs__msg__FailsafeTrigger__Sequence__are_equal(const orca_msgs__msg__FailsafeTrigger__Sequence * lhs, const orca_msgs__msg__FailsafeTrigger__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!orca_msgs__msg__FailsafeTrigger__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
orca_msgs__msg__FailsafeTrigger__Sequence__copy(
  const orca_msgs__msg__FailsafeTrigger__Sequence * input,
  orca_msgs__msg__FailsafeTrigger__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(orca_msgs__msg__FailsafeTrigger)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(orca_msgs__msg__FailsafeTrigger);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    orca_msgs__msg__FailsafeTrigger * data =
      (orca_msgs__msg__FailsafeTrigger *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!orca_msgs__msg__FailsafeTrigger__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          orca_msgs__msg__FailsafeTrigger__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!orca_msgs__msg__FailsafeTrigger__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
