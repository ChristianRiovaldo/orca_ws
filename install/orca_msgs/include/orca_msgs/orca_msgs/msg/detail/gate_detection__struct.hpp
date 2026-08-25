// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from orca_msgs:msg/GateDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orca_msgs/msg/gate_detection.hpp"


#ifndef ORCA_MSGS__MSG__DETAIL__GATE_DETECTION__STRUCT_HPP_
#define ORCA_MSGS__MSG__DETAIL__GATE_DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__orca_msgs__msg__GateDetection __attribute__((deprecated))
#else
# define DEPRECATED__orca_msgs__msg__GateDetection __declspec(deprecated)
#endif

namespace orca_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GateDetection_
{
  using Type = GateDetection_<ContainerAllocator>;

  explicit GateDetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->detected = false;
      this->class_name = "";
      this->confidence = 0.0f;
      this->center_x = 0.0f;
      this->center_y = 0.0f;
      this->center_x_norm = 0.0f;
      this->bbox_width = 0.0f;
      this->bbox_height = 0.0f;
      this->bbox_area_ratio = 0.0f;
      this->distance = 0.0f;
    }
  }

  explicit GateDetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : class_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->detected = false;
      this->class_name = "";
      this->confidence = 0.0f;
      this->center_x = 0.0f;
      this->center_y = 0.0f;
      this->center_x_norm = 0.0f;
      this->bbox_width = 0.0f;
      this->bbox_height = 0.0f;
      this->bbox_area_ratio = 0.0f;
      this->distance = 0.0f;
    }
  }

  // field types and members
  using _detected_type =
    bool;
  _detected_type detected;
  using _class_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _class_name_type class_name;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _center_x_type =
    float;
  _center_x_type center_x;
  using _center_y_type =
    float;
  _center_y_type center_y;
  using _center_x_norm_type =
    float;
  _center_x_norm_type center_x_norm;
  using _bbox_width_type =
    float;
  _bbox_width_type bbox_width;
  using _bbox_height_type =
    float;
  _bbox_height_type bbox_height;
  using _bbox_area_ratio_type =
    float;
  _bbox_area_ratio_type bbox_area_ratio;
  using _distance_type =
    float;
  _distance_type distance;

  // setters for named parameter idiom
  Type & set__detected(
    const bool & _arg)
  {
    this->detected = _arg;
    return *this;
  }
  Type & set__class_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->class_name = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__center_x(
    const float & _arg)
  {
    this->center_x = _arg;
    return *this;
  }
  Type & set__center_y(
    const float & _arg)
  {
    this->center_y = _arg;
    return *this;
  }
  Type & set__center_x_norm(
    const float & _arg)
  {
    this->center_x_norm = _arg;
    return *this;
  }
  Type & set__bbox_width(
    const float & _arg)
  {
    this->bbox_width = _arg;
    return *this;
  }
  Type & set__bbox_height(
    const float & _arg)
  {
    this->bbox_height = _arg;
    return *this;
  }
  Type & set__bbox_area_ratio(
    const float & _arg)
  {
    this->bbox_area_ratio = _arg;
    return *this;
  }
  Type & set__distance(
    const float & _arg)
  {
    this->distance = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    orca_msgs::msg::GateDetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const orca_msgs::msg::GateDetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<orca_msgs::msg::GateDetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<orca_msgs::msg::GateDetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      orca_msgs::msg::GateDetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<orca_msgs::msg::GateDetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      orca_msgs::msg::GateDetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<orca_msgs::msg::GateDetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<orca_msgs::msg::GateDetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<orca_msgs::msg::GateDetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__orca_msgs__msg__GateDetection
    std::shared_ptr<orca_msgs::msg::GateDetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__orca_msgs__msg__GateDetection
    std::shared_ptr<orca_msgs::msg::GateDetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GateDetection_ & other) const
  {
    if (this->detected != other.detected) {
      return false;
    }
    if (this->class_name != other.class_name) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->center_x != other.center_x) {
      return false;
    }
    if (this->center_y != other.center_y) {
      return false;
    }
    if (this->center_x_norm != other.center_x_norm) {
      return false;
    }
    if (this->bbox_width != other.bbox_width) {
      return false;
    }
    if (this->bbox_height != other.bbox_height) {
      return false;
    }
    if (this->bbox_area_ratio != other.bbox_area_ratio) {
      return false;
    }
    if (this->distance != other.distance) {
      return false;
    }
    return true;
  }
  bool operator!=(const GateDetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GateDetection_

// alias to use template instance with default allocator
using GateDetection =
  orca_msgs::msg::GateDetection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace orca_msgs

#endif  // ORCA_MSGS__MSG__DETAIL__GATE_DETECTION__STRUCT_HPP_
