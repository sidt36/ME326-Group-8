// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pose_traj_controller:action/MoveToPose.idl
// generated code does not contain a copyright notice

#ifndef POSE_TRAJ_CONTROLLER__ACTION__DETAIL__MOVE_TO_POSE__STRUCT_HPP_
#define POSE_TRAJ_CONTROLLER__ACTION__DETAIL__MOVE_TO_POSE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pose_traj_controller__action__MoveToPose_Goal __attribute__((deprecated))
#else
# define DEPRECATED__pose_traj_controller__action__MoveToPose_Goal __declspec(deprecated)
#endif

namespace pose_traj_controller
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoveToPose_Goal_
{
  using Type = MoveToPose_Goal_<ContainerAllocator>;

  explicit MoveToPose_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->yaw = 0.0;
      this->orientation_required = false;
    }
  }

  explicit MoveToPose_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->yaw = 0.0;
      this->orientation_required = false;
    }
  }

  // field types and members
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;
  using _yaw_type =
    double;
  _yaw_type yaw;
  using _orientation_required_type =
    bool;
  _orientation_required_type orientation_required;

  // setters for named parameter idiom
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__yaw(
    const double & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__orientation_required(
    const bool & _arg)
  {
    this->orientation_required = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pose_traj_controller::action::MoveToPose_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const pose_traj_controller::action::MoveToPose_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pose_traj_controller::action::MoveToPose_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pose_traj_controller::action::MoveToPose_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pose_traj_controller::action::MoveToPose_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pose_traj_controller::action::MoveToPose_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pose_traj_controller::action::MoveToPose_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pose_traj_controller::action::MoveToPose_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pose_traj_controller::action::MoveToPose_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pose_traj_controller::action::MoveToPose_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pose_traj_controller__action__MoveToPose_Goal
    std::shared_ptr<pose_traj_controller::action::MoveToPose_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pose_traj_controller__action__MoveToPose_Goal
    std::shared_ptr<pose_traj_controller::action::MoveToPose_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveToPose_Goal_ & other) const
  {
    if (this->position != other.position) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->orientation_required != other.orientation_required) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveToPose_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveToPose_Goal_

// alias to use template instance with default allocator
using MoveToPose_Goal =
  pose_traj_controller::action::MoveToPose_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace pose_traj_controller


#ifndef _WIN32
# define DEPRECATED__pose_traj_controller__action__MoveToPose_Result __attribute__((deprecated))
#else
# define DEPRECATED__pose_traj_controller__action__MoveToPose_Result __declspec(deprecated)
#endif

namespace pose_traj_controller
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoveToPose_Result_
{
  using Type = MoveToPose_Result_<ContainerAllocator>;

  explicit MoveToPose_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pose_reached = false;
    }
  }

  explicit MoveToPose_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pose_reached = false;
    }
  }

  // field types and members
  using _pose_reached_type =
    bool;
  _pose_reached_type pose_reached;

  // setters for named parameter idiom
  Type & set__pose_reached(
    const bool & _arg)
  {
    this->pose_reached = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pose_traj_controller::action::MoveToPose_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const pose_traj_controller::action::MoveToPose_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pose_traj_controller::action::MoveToPose_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pose_traj_controller::action::MoveToPose_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pose_traj_controller::action::MoveToPose_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pose_traj_controller::action::MoveToPose_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pose_traj_controller::action::MoveToPose_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pose_traj_controller::action::MoveToPose_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pose_traj_controller::action::MoveToPose_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pose_traj_controller::action::MoveToPose_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pose_traj_controller__action__MoveToPose_Result
    std::shared_ptr<pose_traj_controller::action::MoveToPose_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pose_traj_controller__action__MoveToPose_Result
    std::shared_ptr<pose_traj_controller::action::MoveToPose_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveToPose_Result_ & other) const
  {
    if (this->pose_reached != other.pose_reached) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveToPose_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveToPose_Result_

// alias to use template instance with default allocator
using MoveToPose_Result =
  pose_traj_controller::action::MoveToPose_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace pose_traj_controller


#ifndef _WIN32
# define DEPRECATED__pose_traj_controller__action__MoveToPose_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__pose_traj_controller__action__MoveToPose_Feedback __declspec(deprecated)
#endif

namespace pose_traj_controller
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoveToPose_Feedback_
{
  using Type = MoveToPose_Feedback_<ContainerAllocator>;

  explicit MoveToPose_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->feedback_string = "";
    }
  }

  explicit MoveToPose_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : feedback_string(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->feedback_string = "";
    }
  }

  // field types and members
  using _feedback_string_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _feedback_string_type feedback_string;

  // setters for named parameter idiom
  Type & set__feedback_string(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->feedback_string = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pose_traj_controller::action::MoveToPose_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const pose_traj_controller::action::MoveToPose_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pose_traj_controller::action::MoveToPose_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pose_traj_controller::action::MoveToPose_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pose_traj_controller::action::MoveToPose_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pose_traj_controller::action::MoveToPose_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pose_traj_controller::action::MoveToPose_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pose_traj_controller::action::MoveToPose_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pose_traj_controller::action::MoveToPose_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pose_traj_controller::action::MoveToPose_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pose_traj_controller__action__MoveToPose_Feedback
    std::shared_ptr<pose_traj_controller::action::MoveToPose_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pose_traj_controller__action__MoveToPose_Feedback
    std::shared_ptr<pose_traj_controller::action::MoveToPose_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveToPose_Feedback_ & other) const
  {
    if (this->feedback_string != other.feedback_string) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveToPose_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveToPose_Feedback_

// alias to use template instance with default allocator
using MoveToPose_Feedback =
  pose_traj_controller::action::MoveToPose_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace pose_traj_controller


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "pose_traj_controller/action/detail/move_to_pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pose_traj_controller__action__MoveToPose_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__pose_traj_controller__action__MoveToPose_SendGoal_Request __declspec(deprecated)
#endif

namespace pose_traj_controller
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoveToPose_SendGoal_Request_
{
  using Type = MoveToPose_SendGoal_Request_<ContainerAllocator>;

  explicit MoveToPose_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit MoveToPose_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    pose_traj_controller::action::MoveToPose_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const pose_traj_controller::action::MoveToPose_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pose_traj_controller::action::MoveToPose_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const pose_traj_controller::action::MoveToPose_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pose_traj_controller::action::MoveToPose_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pose_traj_controller::action::MoveToPose_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pose_traj_controller::action::MoveToPose_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pose_traj_controller::action::MoveToPose_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pose_traj_controller::action::MoveToPose_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pose_traj_controller::action::MoveToPose_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pose_traj_controller::action::MoveToPose_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pose_traj_controller::action::MoveToPose_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pose_traj_controller__action__MoveToPose_SendGoal_Request
    std::shared_ptr<pose_traj_controller::action::MoveToPose_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pose_traj_controller__action__MoveToPose_SendGoal_Request
    std::shared_ptr<pose_traj_controller::action::MoveToPose_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveToPose_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveToPose_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveToPose_SendGoal_Request_

// alias to use template instance with default allocator
using MoveToPose_SendGoal_Request =
  pose_traj_controller::action::MoveToPose_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace pose_traj_controller


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pose_traj_controller__action__MoveToPose_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__pose_traj_controller__action__MoveToPose_SendGoal_Response __declspec(deprecated)
#endif

namespace pose_traj_controller
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoveToPose_SendGoal_Response_
{
  using Type = MoveToPose_SendGoal_Response_<ContainerAllocator>;

  explicit MoveToPose_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit MoveToPose_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pose_traj_controller::action::MoveToPose_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const pose_traj_controller::action::MoveToPose_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pose_traj_controller::action::MoveToPose_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pose_traj_controller::action::MoveToPose_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pose_traj_controller::action::MoveToPose_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pose_traj_controller::action::MoveToPose_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pose_traj_controller::action::MoveToPose_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pose_traj_controller::action::MoveToPose_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pose_traj_controller::action::MoveToPose_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pose_traj_controller::action::MoveToPose_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pose_traj_controller__action__MoveToPose_SendGoal_Response
    std::shared_ptr<pose_traj_controller::action::MoveToPose_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pose_traj_controller__action__MoveToPose_SendGoal_Response
    std::shared_ptr<pose_traj_controller::action::MoveToPose_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveToPose_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveToPose_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveToPose_SendGoal_Response_

// alias to use template instance with default allocator
using MoveToPose_SendGoal_Response =
  pose_traj_controller::action::MoveToPose_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace pose_traj_controller

namespace pose_traj_controller
{

namespace action
{

struct MoveToPose_SendGoal
{
  using Request = pose_traj_controller::action::MoveToPose_SendGoal_Request;
  using Response = pose_traj_controller::action::MoveToPose_SendGoal_Response;
};

}  // namespace action

}  // namespace pose_traj_controller


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pose_traj_controller__action__MoveToPose_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__pose_traj_controller__action__MoveToPose_GetResult_Request __declspec(deprecated)
#endif

namespace pose_traj_controller
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoveToPose_GetResult_Request_
{
  using Type = MoveToPose_GetResult_Request_<ContainerAllocator>;

  explicit MoveToPose_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit MoveToPose_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pose_traj_controller::action::MoveToPose_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const pose_traj_controller::action::MoveToPose_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pose_traj_controller::action::MoveToPose_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pose_traj_controller::action::MoveToPose_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pose_traj_controller::action::MoveToPose_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pose_traj_controller::action::MoveToPose_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pose_traj_controller::action::MoveToPose_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pose_traj_controller::action::MoveToPose_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pose_traj_controller::action::MoveToPose_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pose_traj_controller::action::MoveToPose_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pose_traj_controller__action__MoveToPose_GetResult_Request
    std::shared_ptr<pose_traj_controller::action::MoveToPose_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pose_traj_controller__action__MoveToPose_GetResult_Request
    std::shared_ptr<pose_traj_controller::action::MoveToPose_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveToPose_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveToPose_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveToPose_GetResult_Request_

// alias to use template instance with default allocator
using MoveToPose_GetResult_Request =
  pose_traj_controller::action::MoveToPose_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace pose_traj_controller


// Include directives for member types
// Member 'result'
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pose_traj_controller__action__MoveToPose_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__pose_traj_controller__action__MoveToPose_GetResult_Response __declspec(deprecated)
#endif

namespace pose_traj_controller
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoveToPose_GetResult_Response_
{
  using Type = MoveToPose_GetResult_Response_<ContainerAllocator>;

  explicit MoveToPose_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit MoveToPose_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    pose_traj_controller::action::MoveToPose_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const pose_traj_controller::action::MoveToPose_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pose_traj_controller::action::MoveToPose_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const pose_traj_controller::action::MoveToPose_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pose_traj_controller::action::MoveToPose_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pose_traj_controller::action::MoveToPose_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pose_traj_controller::action::MoveToPose_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pose_traj_controller::action::MoveToPose_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pose_traj_controller::action::MoveToPose_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pose_traj_controller::action::MoveToPose_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pose_traj_controller::action::MoveToPose_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pose_traj_controller::action::MoveToPose_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pose_traj_controller__action__MoveToPose_GetResult_Response
    std::shared_ptr<pose_traj_controller::action::MoveToPose_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pose_traj_controller__action__MoveToPose_GetResult_Response
    std::shared_ptr<pose_traj_controller::action::MoveToPose_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveToPose_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveToPose_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveToPose_GetResult_Response_

// alias to use template instance with default allocator
using MoveToPose_GetResult_Response =
  pose_traj_controller::action::MoveToPose_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace pose_traj_controller

namespace pose_traj_controller
{

namespace action
{

struct MoveToPose_GetResult
{
  using Request = pose_traj_controller::action::MoveToPose_GetResult_Request;
  using Response = pose_traj_controller::action::MoveToPose_GetResult_Response;
};

}  // namespace action

}  // namespace pose_traj_controller


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pose_traj_controller__action__MoveToPose_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__pose_traj_controller__action__MoveToPose_FeedbackMessage __declspec(deprecated)
#endif

namespace pose_traj_controller
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoveToPose_FeedbackMessage_
{
  using Type = MoveToPose_FeedbackMessage_<ContainerAllocator>;

  explicit MoveToPose_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit MoveToPose_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    pose_traj_controller::action::MoveToPose_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const pose_traj_controller::action::MoveToPose_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pose_traj_controller::action::MoveToPose_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const pose_traj_controller::action::MoveToPose_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pose_traj_controller::action::MoveToPose_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pose_traj_controller::action::MoveToPose_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pose_traj_controller::action::MoveToPose_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pose_traj_controller::action::MoveToPose_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pose_traj_controller::action::MoveToPose_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pose_traj_controller::action::MoveToPose_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pose_traj_controller::action::MoveToPose_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pose_traj_controller::action::MoveToPose_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pose_traj_controller__action__MoveToPose_FeedbackMessage
    std::shared_ptr<pose_traj_controller::action::MoveToPose_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pose_traj_controller__action__MoveToPose_FeedbackMessage
    std::shared_ptr<pose_traj_controller::action::MoveToPose_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveToPose_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveToPose_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveToPose_FeedbackMessage_

// alias to use template instance with default allocator
using MoveToPose_FeedbackMessage =
  pose_traj_controller::action::MoveToPose_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace pose_traj_controller

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace pose_traj_controller
{

namespace action
{

struct MoveToPose
{
  /// The goal message defined in the action definition.
  using Goal = pose_traj_controller::action::MoveToPose_Goal;
  /// The result message defined in the action definition.
  using Result = pose_traj_controller::action::MoveToPose_Result;
  /// The feedback message defined in the action definition.
  using Feedback = pose_traj_controller::action::MoveToPose_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = pose_traj_controller::action::MoveToPose_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = pose_traj_controller::action::MoveToPose_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = pose_traj_controller::action::MoveToPose_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct MoveToPose MoveToPose;

}  // namespace action

}  // namespace pose_traj_controller

#endif  // POSE_TRAJ_CONTROLLER__ACTION__DETAIL__MOVE_TO_POSE__STRUCT_HPP_
