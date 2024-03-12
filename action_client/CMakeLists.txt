cmake_minimum_required(VERSION 3.8)
project(action_client)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(project_messages REQUIRED)
find_package(la_msgs REQUIRED)
find_package(rclpy REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(action_msgs REQUIRED)


ament_python_install_package(${PROJECT_NAME})

# Install Python nodes
install(PROGRAMS
  ${PROJECT_NAME}/move_base_client.py
  ${PROJECT_NAME}/move_arm_named_pose_client.py
  ${PROJECT_NAME}/pick_or_place_client.py
  ${PROJECT_NAME}/perception_client.py
  DESTINATION lib/${PROJECT_NAME}
)
  
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
