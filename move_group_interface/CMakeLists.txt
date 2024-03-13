cmake_minimum_required(VERSION 3.8)
project(move_group_interface)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(project_messages REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(geometric_shapes REQUIRED)
find_package(moveit_msgs REQUIRED)



# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()


add_executable(${PROJECT_NAME}_named_pose_server src/move_arm_named_pose_action_server.cpp)

ament_target_dependencies(
  ${PROJECT_NAME}_named_pose_server
  rclcpp
  rclcpp_action
  geometry_msgs
  moveit_ros_planning_interface
  tf2_ros
  tf2_geometry_msgs
  project_messages
  moveit_msgs
  geometric_shapes
)

install(TARGETS
  ${PROJECT_NAME}_named_pose_server
  DESTINATION lib/${PROJECT_NAME}
)

add_executable(${PROJECT_NAME}_pick_or_place_server src/arm_pick_or_place_server.cpp)

ament_target_dependencies(
  ${PROJECT_NAME}_pick_or_place_server
  rclcpp
  rclcpp_action
  geometry_msgs
  moveit_ros_planning_interface
  tf2_ros
  tf2_geometry_msgs
  project_messages
  moveit_msgs
  geometric_shapes
)


install(TARGETS
  ${PROJECT_NAME}_pick_or_place_server
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()