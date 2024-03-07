cmake_minimum_required(VERSION 3.8)
project(pose_traj_controller)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclpy REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(project_messages REQUIRED)


# Install Python modules
ament_python_install_package(${PROJECT_NAME})


# Install Python executables
install(PROGRAMS
pose_traj_controller/pose_traj_controller
  DESTINATION lib/${PROJECT_NAME}
)

# Action Perception node
add_executable(visual_block_perception_srv src/visual_block_perception_srv.cpp)
ament_target_dependencies(visual_block_perception_srv rclcpp std_msgs geometry_msgs sensor_msgs image_transport cv_bridge tf2_ros tf2_eigen visualization_msgs)
install(TARGETS
  visual_block_perception_srv
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()


