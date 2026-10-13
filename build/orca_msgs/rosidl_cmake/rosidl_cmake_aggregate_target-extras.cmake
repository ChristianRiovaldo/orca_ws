# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target orca_msgs::orca_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${orca_msgs_TARGETS}.
if(orca_msgs_TARGETS AND NOT TARGET orca_msgs::orca_msgs)
  add_library(orca_msgs::orca_msgs INTERFACE IMPORTED)
  set_target_properties(orca_msgs::orca_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${orca_msgs_TARGETS}")
endif()
