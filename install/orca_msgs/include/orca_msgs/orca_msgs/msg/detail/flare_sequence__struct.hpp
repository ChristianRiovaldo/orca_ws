// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from orca_msgs:msg/FlareSequence.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orca_msgs/msg/flare_sequence.hpp"


#ifndef ORCA_MSGS__MSG__DETAIL__FLARE_SEQUENCE__STRUCT_HPP_
#define ORCA_MSGS__MSG__DETAIL__FLARE_SEQUENCE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__orca_msgs__msg__FlareSequence __attribute__((deprecated))
#else
# define DEPRECATED__orca_msgs__msg__FlareSequence __declspec(deprecated)
#endif

namespace orca_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FlareSequence_
{
  using Type = FlareSequence_<ContainerAllocator>;

  explicit FlareSequence_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sequence = "";
    }
  }

  explicit FlareSequence_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : sequence(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sequence = "";
    }
  }

  // field types and members
  using _sequence_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _sequence_type sequence;

  // setters for named parameter idiom
  Type & set__sequence(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->sequence = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    orca_msgs::msg::FlareSequence_<ContainerAllocator> *;
  using ConstRawPtr =
    const orca_msgs::msg::FlareSequence_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<orca_msgs::msg::FlareSequence_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<orca_msgs::msg::FlareSequence_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      orca_msgs::msg::FlareSequence_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<orca_msgs::msg::FlareSequence_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      orca_msgs::msg::FlareSequence_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<orca_msgs::msg::FlareSequence_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<orca_msgs::msg::FlareSequence_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<orca_msgs::msg::FlareSequence_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__orca_msgs__msg__FlareSequence
    std::shared_ptr<orca_msgs::msg::FlareSequence_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__orca_msgs__msg__FlareSequence
    std::shared_ptr<orca_msgs::msg::FlareSequence_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FlareSequence_ & other) const
  {
    if (this->sequence != other.sequence) {
      return false;
    }
    return true;
  }
  bool operator!=(const FlareSequence_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FlareSequence_

// alias to use template instance with default allocator
using FlareSequence =
  orca_msgs::msg::FlareSequence_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace orca_msgs

#endif  // ORCA_MSGS__MSG__DETAIL__FLARE_SEQUENCE__STRUCT_HPP_
