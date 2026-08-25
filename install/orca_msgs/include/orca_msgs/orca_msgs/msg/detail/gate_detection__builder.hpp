// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from orca_msgs:msg/GateDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orca_msgs/msg/gate_detection.hpp"


#ifndef ORCA_MSGS__MSG__DETAIL__GATE_DETECTION__BUILDER_HPP_
#define ORCA_MSGS__MSG__DETAIL__GATE_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "orca_msgs/msg/detail/gate_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace orca_msgs
{

namespace msg
{

namespace builder
{

class Init_GateDetection_distance
{
public:
  explicit Init_GateDetection_distance(::orca_msgs::msg::GateDetection & msg)
  : msg_(msg)
  {}
  ::orca_msgs::msg::GateDetection distance(::orca_msgs::msg::GateDetection::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::orca_msgs::msg::GateDetection msg_;
};

class Init_GateDetection_bbox_area_ratio
{
public:
  explicit Init_GateDetection_bbox_area_ratio(::orca_msgs::msg::GateDetection & msg)
  : msg_(msg)
  {}
  Init_GateDetection_distance bbox_area_ratio(::orca_msgs::msg::GateDetection::_bbox_area_ratio_type arg)
  {
    msg_.bbox_area_ratio = std::move(arg);
    return Init_GateDetection_distance(msg_);
  }

private:
  ::orca_msgs::msg::GateDetection msg_;
};

class Init_GateDetection_bbox_height
{
public:
  explicit Init_GateDetection_bbox_height(::orca_msgs::msg::GateDetection & msg)
  : msg_(msg)
  {}
  Init_GateDetection_bbox_area_ratio bbox_height(::orca_msgs::msg::GateDetection::_bbox_height_type arg)
  {
    msg_.bbox_height = std::move(arg);
    return Init_GateDetection_bbox_area_ratio(msg_);
  }

private:
  ::orca_msgs::msg::GateDetection msg_;
};

class Init_GateDetection_bbox_width
{
public:
  explicit Init_GateDetection_bbox_width(::orca_msgs::msg::GateDetection & msg)
  : msg_(msg)
  {}
  Init_GateDetection_bbox_height bbox_width(::orca_msgs::msg::GateDetection::_bbox_width_type arg)
  {
    msg_.bbox_width = std::move(arg);
    return Init_GateDetection_bbox_height(msg_);
  }

private:
  ::orca_msgs::msg::GateDetection msg_;
};

class Init_GateDetection_center_x_norm
{
public:
  explicit Init_GateDetection_center_x_norm(::orca_msgs::msg::GateDetection & msg)
  : msg_(msg)
  {}
  Init_GateDetection_bbox_width center_x_norm(::orca_msgs::msg::GateDetection::_center_x_norm_type arg)
  {
    msg_.center_x_norm = std::move(arg);
    return Init_GateDetection_bbox_width(msg_);
  }

private:
  ::orca_msgs::msg::GateDetection msg_;
};

class Init_GateDetection_center_y
{
public:
  explicit Init_GateDetection_center_y(::orca_msgs::msg::GateDetection & msg)
  : msg_(msg)
  {}
  Init_GateDetection_center_x_norm center_y(::orca_msgs::msg::GateDetection::_center_y_type arg)
  {
    msg_.center_y = std::move(arg);
    return Init_GateDetection_center_x_norm(msg_);
  }

private:
  ::orca_msgs::msg::GateDetection msg_;
};

class Init_GateDetection_center_x
{
public:
  explicit Init_GateDetection_center_x(::orca_msgs::msg::GateDetection & msg)
  : msg_(msg)
  {}
  Init_GateDetection_center_y center_x(::orca_msgs::msg::GateDetection::_center_x_type arg)
  {
    msg_.center_x = std::move(arg);
    return Init_GateDetection_center_y(msg_);
  }

private:
  ::orca_msgs::msg::GateDetection msg_;
};

class Init_GateDetection_confidence
{
public:
  explicit Init_GateDetection_confidence(::orca_msgs::msg::GateDetection & msg)
  : msg_(msg)
  {}
  Init_GateDetection_center_x confidence(::orca_msgs::msg::GateDetection::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_GateDetection_center_x(msg_);
  }

private:
  ::orca_msgs::msg::GateDetection msg_;
};

class Init_GateDetection_class_name
{
public:
  explicit Init_GateDetection_class_name(::orca_msgs::msg::GateDetection & msg)
  : msg_(msg)
  {}
  Init_GateDetection_confidence class_name(::orca_msgs::msg::GateDetection::_class_name_type arg)
  {
    msg_.class_name = std::move(arg);
    return Init_GateDetection_confidence(msg_);
  }

private:
  ::orca_msgs::msg::GateDetection msg_;
};

class Init_GateDetection_detected
{
public:
  Init_GateDetection_detected()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GateDetection_class_name detected(::orca_msgs::msg::GateDetection::_detected_type arg)
  {
    msg_.detected = std::move(arg);
    return Init_GateDetection_class_name(msg_);
  }

private:
  ::orca_msgs::msg::GateDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::orca_msgs::msg::GateDetection>()
{
  return orca_msgs::msg::builder::Init_GateDetection_detected();
}

}  // namespace orca_msgs

#endif  // ORCA_MSGS__MSG__DETAIL__GATE_DETECTION__BUILDER_HPP_
