// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from orca_msgs:msg/OrcaAttitude.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orca_msgs/msg/orca_attitude.hpp"


#ifndef ORCA_MSGS__MSG__DETAIL__ORCA_ATTITUDE__STRUCT_HPP_
#define ORCA_MSGS__MSG__DETAIL__ORCA_ATTITUDE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__orca_msgs__msg__OrcaAttitude __attribute__((deprecated))
#else
# define DEPRECATED__orca_msgs__msg__OrcaAttitude __declspec(deprecated)
#endif

namespace orca_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OrcaAttitude_
{
  using Type = OrcaAttitude_<ContainerAllocator>;

  explicit OrcaAttitude_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->initial_x = 0.0f;
      this->initial_y = 0.0f;
      this->initial_z = 0.0f;
      this->yaw_deg = 0.0f;
      this->initial_deg = 0.0f;
      this->roll_deg = 0.0f;
      this->pitch_deg = 0.0f;
      this->rollspeed_deg_s = 0.0f;
      this->pitchspeed_deg_s = 0.0f;
      this->yawspeed_deg_s = 0.0f;
    }
  }

  explicit OrcaAttitude_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->initial_x = 0.0f;
      this->initial_y = 0.0f;
      this->initial_z = 0.0f;
      this->yaw_deg = 0.0f;
      this->initial_deg = 0.0f;
      this->roll_deg = 0.0f;
      this->pitch_deg = 0.0f;
      this->rollspeed_deg_s = 0.0f;
      this->pitchspeed_deg_s = 0.0f;
      this->yawspeed_deg_s = 0.0f;
    }
  }

  // field types and members
  using _initial_x_type =
    float;
  _initial_x_type initial_x;
  using _initial_y_type =
    float;
  _initial_y_type initial_y;
  using _initial_z_type =
    float;
  _initial_z_type initial_z;
  using _yaw_deg_type =
    float;
  _yaw_deg_type yaw_deg;
  using _initial_deg_type =
    float;
  _initial_deg_type initial_deg;
  using _roll_deg_type =
    float;
  _roll_deg_type roll_deg;
  using _pitch_deg_type =
    float;
  _pitch_deg_type pitch_deg;
  using _rollspeed_deg_s_type =
    float;
  _rollspeed_deg_s_type rollspeed_deg_s;
  using _pitchspeed_deg_s_type =
    float;
  _pitchspeed_deg_s_type pitchspeed_deg_s;
  using _yawspeed_deg_s_type =
    float;
  _yawspeed_deg_s_type yawspeed_deg_s;

  // setters for named parameter idiom
  Type & set__initial_x(
    const float & _arg)
  {
    this->initial_x = _arg;
    return *this;
  }
  Type & set__initial_y(
    const float & _arg)
  {
    this->initial_y = _arg;
    return *this;
  }
  Type & set__initial_z(
    const float & _arg)
  {
    this->initial_z = _arg;
    return *this;
  }
  Type & set__yaw_deg(
    const float & _arg)
  {
    this->yaw_deg = _arg;
    return *this;
  }
  Type & set__initial_deg(
    const float & _arg)
  {
    this->initial_deg = _arg;
    return *this;
  }
  Type & set__roll_deg(
    const float & _arg)
  {
    this->roll_deg = _arg;
    return *this;
  }
  Type & set__pitch_deg(
    const float & _arg)
  {
    this->pitch_deg = _arg;
    return *this;
  }
  Type & set__rollspeed_deg_s(
    const float & _arg)
  {
    this->rollspeed_deg_s = _arg;
    return *this;
  }
  Type & set__pitchspeed_deg_s(
    const float & _arg)
  {
    this->pitchspeed_deg_s = _arg;
    return *this;
  }
  Type & set__yawspeed_deg_s(
    const float & _arg)
  {
    this->yawspeed_deg_s = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    orca_msgs::msg::OrcaAttitude_<ContainerAllocator> *;
  using ConstRawPtr =
    const orca_msgs::msg::OrcaAttitude_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<orca_msgs::msg::OrcaAttitude_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<orca_msgs::msg::OrcaAttitude_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      orca_msgs::msg::OrcaAttitude_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<orca_msgs::msg::OrcaAttitude_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      orca_msgs::msg::OrcaAttitude_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<orca_msgs::msg::OrcaAttitude_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<orca_msgs::msg::OrcaAttitude_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<orca_msgs::msg::OrcaAttitude_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__orca_msgs__msg__OrcaAttitude
    std::shared_ptr<orca_msgs::msg::OrcaAttitude_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__orca_msgs__msg__OrcaAttitude
    std::shared_ptr<orca_msgs::msg::OrcaAttitude_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OrcaAttitude_ & other) const
  {
    if (this->initial_x != other.initial_x) {
      return false;
    }
    if (this->initial_y != other.initial_y) {
      return false;
    }
    if (this->initial_z != other.initial_z) {
      return false;
    }
    if (this->yaw_deg != other.yaw_deg) {
      return false;
    }
    if (this->initial_deg != other.initial_deg) {
      return false;
    }
    if (this->roll_deg != other.roll_deg) {
      return false;
    }
    if (this->pitch_deg != other.pitch_deg) {
      return false;
    }
    if (this->rollspeed_deg_s != other.rollspeed_deg_s) {
      return false;
    }
    if (this->pitchspeed_deg_s != other.pitchspeed_deg_s) {
      return false;
    }
    if (this->yawspeed_deg_s != other.yawspeed_deg_s) {
      return false;
    }
    return true;
  }
  bool operator!=(const OrcaAttitude_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OrcaAttitude_

// alias to use template instance with default allocator
using OrcaAttitude =
  orca_msgs::msg::OrcaAttitude_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace orca_msgs

#endif  // ORCA_MSGS__MSG__DETAIL__ORCA_ATTITUDE__STRUCT_HPP_
