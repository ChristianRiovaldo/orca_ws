// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from orca_msgs:msg/OrcaControl.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orca_msgs/msg/orca_control.hpp"


#ifndef ORCA_MSGS__MSG__DETAIL__ORCA_CONTROL__STRUCT_HPP_
#define ORCA_MSGS__MSG__DETAIL__ORCA_CONTROL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__orca_msgs__msg__OrcaControl __attribute__((deprecated))
#else
# define DEPRECATED__orca_msgs__msg__OrcaControl __declspec(deprecated)
#endif

namespace orca_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OrcaControl_
{
  using Type = OrcaControl_<ContainerAllocator>;

  explicit OrcaControl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->throttle = 0;
      this->lateral = 0;
      this->forward = 0;
      this->yaw = 0;
      this->arm_mode = "";
      this->control_mode = "";
      this->gripper_mode = "";
      this->source = "";
    }
  }

  explicit OrcaControl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : arm_mode(_alloc),
    control_mode(_alloc),
    gripper_mode(_alloc),
    source(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->throttle = 0;
      this->lateral = 0;
      this->forward = 0;
      this->yaw = 0;
      this->arm_mode = "";
      this->control_mode = "";
      this->gripper_mode = "";
      this->source = "";
    }
  }

  // field types and members
  using _throttle_type =
    int16_t;
  _throttle_type throttle;
  using _lateral_type =
    int16_t;
  _lateral_type lateral;
  using _forward_type =
    int16_t;
  _forward_type forward;
  using _yaw_type =
    int16_t;
  _yaw_type yaw;
  using _arm_mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _arm_mode_type arm_mode;
  using _control_mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _control_mode_type control_mode;
  using _gripper_mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _gripper_mode_type gripper_mode;
  using _source_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _source_type source;

  // setters for named parameter idiom
  Type & set__throttle(
    const int16_t & _arg)
  {
    this->throttle = _arg;
    return *this;
  }
  Type & set__lateral(
    const int16_t & _arg)
  {
    this->lateral = _arg;
    return *this;
  }
  Type & set__forward(
    const int16_t & _arg)
  {
    this->forward = _arg;
    return *this;
  }
  Type & set__yaw(
    const int16_t & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__arm_mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->arm_mode = _arg;
    return *this;
  }
  Type & set__control_mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->control_mode = _arg;
    return *this;
  }
  Type & set__gripper_mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->gripper_mode = _arg;
    return *this;
  }
  Type & set__source(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->source = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    orca_msgs::msg::OrcaControl_<ContainerAllocator> *;
  using ConstRawPtr =
    const orca_msgs::msg::OrcaControl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<orca_msgs::msg::OrcaControl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<orca_msgs::msg::OrcaControl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      orca_msgs::msg::OrcaControl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<orca_msgs::msg::OrcaControl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      orca_msgs::msg::OrcaControl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<orca_msgs::msg::OrcaControl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<orca_msgs::msg::OrcaControl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<orca_msgs::msg::OrcaControl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__orca_msgs__msg__OrcaControl
    std::shared_ptr<orca_msgs::msg::OrcaControl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__orca_msgs__msg__OrcaControl
    std::shared_ptr<orca_msgs::msg::OrcaControl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OrcaControl_ & other) const
  {
    if (this->throttle != other.throttle) {
      return false;
    }
    if (this->lateral != other.lateral) {
      return false;
    }
    if (this->forward != other.forward) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->arm_mode != other.arm_mode) {
      return false;
    }
    if (this->control_mode != other.control_mode) {
      return false;
    }
    if (this->gripper_mode != other.gripper_mode) {
      return false;
    }
    if (this->source != other.source) {
      return false;
    }
    return true;
  }
  bool operator!=(const OrcaControl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OrcaControl_

// alias to use template instance with default allocator
using OrcaControl =
  orca_msgs::msg::OrcaControl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace orca_msgs

#endif  // ORCA_MSGS__MSG__DETAIL__ORCA_CONTROL__STRUCT_HPP_
