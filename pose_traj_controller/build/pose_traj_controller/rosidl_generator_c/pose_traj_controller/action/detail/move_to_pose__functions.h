// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from pose_traj_controller:action/MoveToPose.idl
// generated code does not contain a copyright notice

#ifndef POSE_TRAJ_CONTROLLER__ACTION__DETAIL__MOVE_TO_POSE__FUNCTIONS_H_
#define POSE_TRAJ_CONTROLLER__ACTION__DETAIL__MOVE_TO_POSE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "pose_traj_controller/msg/rosidl_generator_c__visibility_control.h"

#include "pose_traj_controller/action/detail/move_to_pose__struct.h"

/// Initialize action/MoveToPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * pose_traj_controller__action__MoveToPose_Goal
 * )) before or use
 * pose_traj_controller__action__MoveToPose_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_Goal__init(pose_traj_controller__action__MoveToPose_Goal * msg);

/// Finalize action/MoveToPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_Goal__fini(pose_traj_controller__action__MoveToPose_Goal * msg);

/// Create action/MoveToPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * pose_traj_controller__action__MoveToPose_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
pose_traj_controller__action__MoveToPose_Goal *
pose_traj_controller__action__MoveToPose_Goal__create();

/// Destroy action/MoveToPose message.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_Goal__destroy(pose_traj_controller__action__MoveToPose_Goal * msg);

/// Check for action/MoveToPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_Goal__are_equal(const pose_traj_controller__action__MoveToPose_Goal * lhs, const pose_traj_controller__action__MoveToPose_Goal * rhs);

/// Copy a action/MoveToPose message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_Goal__copy(
  const pose_traj_controller__action__MoveToPose_Goal * input,
  pose_traj_controller__action__MoveToPose_Goal * output);

/// Initialize array of action/MoveToPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * pose_traj_controller__action__MoveToPose_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_Goal__Sequence__init(pose_traj_controller__action__MoveToPose_Goal__Sequence * array, size_t size);

/// Finalize array of action/MoveToPose messages.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_Goal__Sequence__fini(pose_traj_controller__action__MoveToPose_Goal__Sequence * array);

/// Create array of action/MoveToPose messages.
/**
 * It allocates the memory for the array and calls
 * pose_traj_controller__action__MoveToPose_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
pose_traj_controller__action__MoveToPose_Goal__Sequence *
pose_traj_controller__action__MoveToPose_Goal__Sequence__create(size_t size);

/// Destroy array of action/MoveToPose messages.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_Goal__Sequence__destroy(pose_traj_controller__action__MoveToPose_Goal__Sequence * array);

/// Check for action/MoveToPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_Goal__Sequence__are_equal(const pose_traj_controller__action__MoveToPose_Goal__Sequence * lhs, const pose_traj_controller__action__MoveToPose_Goal__Sequence * rhs);

/// Copy an array of action/MoveToPose messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_Goal__Sequence__copy(
  const pose_traj_controller__action__MoveToPose_Goal__Sequence * input,
  pose_traj_controller__action__MoveToPose_Goal__Sequence * output);

/// Initialize action/MoveToPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * pose_traj_controller__action__MoveToPose_Result
 * )) before or use
 * pose_traj_controller__action__MoveToPose_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_Result__init(pose_traj_controller__action__MoveToPose_Result * msg);

/// Finalize action/MoveToPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_Result__fini(pose_traj_controller__action__MoveToPose_Result * msg);

/// Create action/MoveToPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * pose_traj_controller__action__MoveToPose_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
pose_traj_controller__action__MoveToPose_Result *
pose_traj_controller__action__MoveToPose_Result__create();

/// Destroy action/MoveToPose message.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_Result__destroy(pose_traj_controller__action__MoveToPose_Result * msg);

/// Check for action/MoveToPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_Result__are_equal(const pose_traj_controller__action__MoveToPose_Result * lhs, const pose_traj_controller__action__MoveToPose_Result * rhs);

/// Copy a action/MoveToPose message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_Result__copy(
  const pose_traj_controller__action__MoveToPose_Result * input,
  pose_traj_controller__action__MoveToPose_Result * output);

/// Initialize array of action/MoveToPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * pose_traj_controller__action__MoveToPose_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_Result__Sequence__init(pose_traj_controller__action__MoveToPose_Result__Sequence * array, size_t size);

/// Finalize array of action/MoveToPose messages.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_Result__Sequence__fini(pose_traj_controller__action__MoveToPose_Result__Sequence * array);

/// Create array of action/MoveToPose messages.
/**
 * It allocates the memory for the array and calls
 * pose_traj_controller__action__MoveToPose_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
pose_traj_controller__action__MoveToPose_Result__Sequence *
pose_traj_controller__action__MoveToPose_Result__Sequence__create(size_t size);

/// Destroy array of action/MoveToPose messages.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_Result__Sequence__destroy(pose_traj_controller__action__MoveToPose_Result__Sequence * array);

/// Check for action/MoveToPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_Result__Sequence__are_equal(const pose_traj_controller__action__MoveToPose_Result__Sequence * lhs, const pose_traj_controller__action__MoveToPose_Result__Sequence * rhs);

/// Copy an array of action/MoveToPose messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_Result__Sequence__copy(
  const pose_traj_controller__action__MoveToPose_Result__Sequence * input,
  pose_traj_controller__action__MoveToPose_Result__Sequence * output);

/// Initialize action/MoveToPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * pose_traj_controller__action__MoveToPose_Feedback
 * )) before or use
 * pose_traj_controller__action__MoveToPose_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_Feedback__init(pose_traj_controller__action__MoveToPose_Feedback * msg);

/// Finalize action/MoveToPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_Feedback__fini(pose_traj_controller__action__MoveToPose_Feedback * msg);

/// Create action/MoveToPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * pose_traj_controller__action__MoveToPose_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
pose_traj_controller__action__MoveToPose_Feedback *
pose_traj_controller__action__MoveToPose_Feedback__create();

/// Destroy action/MoveToPose message.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_Feedback__destroy(pose_traj_controller__action__MoveToPose_Feedback * msg);

/// Check for action/MoveToPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_Feedback__are_equal(const pose_traj_controller__action__MoveToPose_Feedback * lhs, const pose_traj_controller__action__MoveToPose_Feedback * rhs);

/// Copy a action/MoveToPose message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_Feedback__copy(
  const pose_traj_controller__action__MoveToPose_Feedback * input,
  pose_traj_controller__action__MoveToPose_Feedback * output);

/// Initialize array of action/MoveToPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * pose_traj_controller__action__MoveToPose_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_Feedback__Sequence__init(pose_traj_controller__action__MoveToPose_Feedback__Sequence * array, size_t size);

/// Finalize array of action/MoveToPose messages.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_Feedback__Sequence__fini(pose_traj_controller__action__MoveToPose_Feedback__Sequence * array);

/// Create array of action/MoveToPose messages.
/**
 * It allocates the memory for the array and calls
 * pose_traj_controller__action__MoveToPose_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
pose_traj_controller__action__MoveToPose_Feedback__Sequence *
pose_traj_controller__action__MoveToPose_Feedback__Sequence__create(size_t size);

/// Destroy array of action/MoveToPose messages.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_Feedback__Sequence__destroy(pose_traj_controller__action__MoveToPose_Feedback__Sequence * array);

/// Check for action/MoveToPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_Feedback__Sequence__are_equal(const pose_traj_controller__action__MoveToPose_Feedback__Sequence * lhs, const pose_traj_controller__action__MoveToPose_Feedback__Sequence * rhs);

/// Copy an array of action/MoveToPose messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_Feedback__Sequence__copy(
  const pose_traj_controller__action__MoveToPose_Feedback__Sequence * input,
  pose_traj_controller__action__MoveToPose_Feedback__Sequence * output);

/// Initialize action/MoveToPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * pose_traj_controller__action__MoveToPose_SendGoal_Request
 * )) before or use
 * pose_traj_controller__action__MoveToPose_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_SendGoal_Request__init(pose_traj_controller__action__MoveToPose_SendGoal_Request * msg);

/// Finalize action/MoveToPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_SendGoal_Request__fini(pose_traj_controller__action__MoveToPose_SendGoal_Request * msg);

/// Create action/MoveToPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * pose_traj_controller__action__MoveToPose_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
pose_traj_controller__action__MoveToPose_SendGoal_Request *
pose_traj_controller__action__MoveToPose_SendGoal_Request__create();

/// Destroy action/MoveToPose message.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_SendGoal_Request__destroy(pose_traj_controller__action__MoveToPose_SendGoal_Request * msg);

/// Check for action/MoveToPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_SendGoal_Request__are_equal(const pose_traj_controller__action__MoveToPose_SendGoal_Request * lhs, const pose_traj_controller__action__MoveToPose_SendGoal_Request * rhs);

/// Copy a action/MoveToPose message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_SendGoal_Request__copy(
  const pose_traj_controller__action__MoveToPose_SendGoal_Request * input,
  pose_traj_controller__action__MoveToPose_SendGoal_Request * output);

/// Initialize array of action/MoveToPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * pose_traj_controller__action__MoveToPose_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence__init(pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/MoveToPose messages.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence__fini(pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence * array);

/// Create array of action/MoveToPose messages.
/**
 * It allocates the memory for the array and calls
 * pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence *
pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/MoveToPose messages.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence__destroy(pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence * array);

/// Check for action/MoveToPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence__are_equal(const pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence * lhs, const pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/MoveToPose messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence__copy(
  const pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence * input,
  pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence * output);

/// Initialize action/MoveToPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * pose_traj_controller__action__MoveToPose_SendGoal_Response
 * )) before or use
 * pose_traj_controller__action__MoveToPose_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_SendGoal_Response__init(pose_traj_controller__action__MoveToPose_SendGoal_Response * msg);

/// Finalize action/MoveToPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_SendGoal_Response__fini(pose_traj_controller__action__MoveToPose_SendGoal_Response * msg);

/// Create action/MoveToPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * pose_traj_controller__action__MoveToPose_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
pose_traj_controller__action__MoveToPose_SendGoal_Response *
pose_traj_controller__action__MoveToPose_SendGoal_Response__create();

/// Destroy action/MoveToPose message.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_SendGoal_Response__destroy(pose_traj_controller__action__MoveToPose_SendGoal_Response * msg);

/// Check for action/MoveToPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_SendGoal_Response__are_equal(const pose_traj_controller__action__MoveToPose_SendGoal_Response * lhs, const pose_traj_controller__action__MoveToPose_SendGoal_Response * rhs);

/// Copy a action/MoveToPose message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_SendGoal_Response__copy(
  const pose_traj_controller__action__MoveToPose_SendGoal_Response * input,
  pose_traj_controller__action__MoveToPose_SendGoal_Response * output);

/// Initialize array of action/MoveToPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * pose_traj_controller__action__MoveToPose_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence__init(pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/MoveToPose messages.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence__fini(pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence * array);

/// Create array of action/MoveToPose messages.
/**
 * It allocates the memory for the array and calls
 * pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence *
pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/MoveToPose messages.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence__destroy(pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence * array);

/// Check for action/MoveToPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence__are_equal(const pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence * lhs, const pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/MoveToPose messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence__copy(
  const pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence * input,
  pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence * output);

/// Initialize action/MoveToPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * pose_traj_controller__action__MoveToPose_GetResult_Request
 * )) before or use
 * pose_traj_controller__action__MoveToPose_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_GetResult_Request__init(pose_traj_controller__action__MoveToPose_GetResult_Request * msg);

/// Finalize action/MoveToPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_GetResult_Request__fini(pose_traj_controller__action__MoveToPose_GetResult_Request * msg);

/// Create action/MoveToPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * pose_traj_controller__action__MoveToPose_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
pose_traj_controller__action__MoveToPose_GetResult_Request *
pose_traj_controller__action__MoveToPose_GetResult_Request__create();

/// Destroy action/MoveToPose message.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_GetResult_Request__destroy(pose_traj_controller__action__MoveToPose_GetResult_Request * msg);

/// Check for action/MoveToPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_GetResult_Request__are_equal(const pose_traj_controller__action__MoveToPose_GetResult_Request * lhs, const pose_traj_controller__action__MoveToPose_GetResult_Request * rhs);

/// Copy a action/MoveToPose message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_GetResult_Request__copy(
  const pose_traj_controller__action__MoveToPose_GetResult_Request * input,
  pose_traj_controller__action__MoveToPose_GetResult_Request * output);

/// Initialize array of action/MoveToPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * pose_traj_controller__action__MoveToPose_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence__init(pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/MoveToPose messages.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence__fini(pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence * array);

/// Create array of action/MoveToPose messages.
/**
 * It allocates the memory for the array and calls
 * pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence *
pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/MoveToPose messages.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence__destroy(pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence * array);

/// Check for action/MoveToPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence__are_equal(const pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence * lhs, const pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence * rhs);

/// Copy an array of action/MoveToPose messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence__copy(
  const pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence * input,
  pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence * output);

/// Initialize action/MoveToPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * pose_traj_controller__action__MoveToPose_GetResult_Response
 * )) before or use
 * pose_traj_controller__action__MoveToPose_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_GetResult_Response__init(pose_traj_controller__action__MoveToPose_GetResult_Response * msg);

/// Finalize action/MoveToPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_GetResult_Response__fini(pose_traj_controller__action__MoveToPose_GetResult_Response * msg);

/// Create action/MoveToPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * pose_traj_controller__action__MoveToPose_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
pose_traj_controller__action__MoveToPose_GetResult_Response *
pose_traj_controller__action__MoveToPose_GetResult_Response__create();

/// Destroy action/MoveToPose message.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_GetResult_Response__destroy(pose_traj_controller__action__MoveToPose_GetResult_Response * msg);

/// Check for action/MoveToPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_GetResult_Response__are_equal(const pose_traj_controller__action__MoveToPose_GetResult_Response * lhs, const pose_traj_controller__action__MoveToPose_GetResult_Response * rhs);

/// Copy a action/MoveToPose message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_GetResult_Response__copy(
  const pose_traj_controller__action__MoveToPose_GetResult_Response * input,
  pose_traj_controller__action__MoveToPose_GetResult_Response * output);

/// Initialize array of action/MoveToPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * pose_traj_controller__action__MoveToPose_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence__init(pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/MoveToPose messages.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence__fini(pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence * array);

/// Create array of action/MoveToPose messages.
/**
 * It allocates the memory for the array and calls
 * pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence *
pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/MoveToPose messages.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence__destroy(pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence * array);

/// Check for action/MoveToPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence__are_equal(const pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence * lhs, const pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence * rhs);

/// Copy an array of action/MoveToPose messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence__copy(
  const pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence * input,
  pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence * output);

/// Initialize action/MoveToPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * pose_traj_controller__action__MoveToPose_FeedbackMessage
 * )) before or use
 * pose_traj_controller__action__MoveToPose_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_FeedbackMessage__init(pose_traj_controller__action__MoveToPose_FeedbackMessage * msg);

/// Finalize action/MoveToPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_FeedbackMessage__fini(pose_traj_controller__action__MoveToPose_FeedbackMessage * msg);

/// Create action/MoveToPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * pose_traj_controller__action__MoveToPose_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
pose_traj_controller__action__MoveToPose_FeedbackMessage *
pose_traj_controller__action__MoveToPose_FeedbackMessage__create();

/// Destroy action/MoveToPose message.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_FeedbackMessage__destroy(pose_traj_controller__action__MoveToPose_FeedbackMessage * msg);

/// Check for action/MoveToPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_FeedbackMessage__are_equal(const pose_traj_controller__action__MoveToPose_FeedbackMessage * lhs, const pose_traj_controller__action__MoveToPose_FeedbackMessage * rhs);

/// Copy a action/MoveToPose message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_FeedbackMessage__copy(
  const pose_traj_controller__action__MoveToPose_FeedbackMessage * input,
  pose_traj_controller__action__MoveToPose_FeedbackMessage * output);

/// Initialize array of action/MoveToPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * pose_traj_controller__action__MoveToPose_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence__init(pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/MoveToPose messages.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence__fini(pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence * array);

/// Create array of action/MoveToPose messages.
/**
 * It allocates the memory for the array and calls
 * pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence *
pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/MoveToPose messages.
/**
 * It calls
 * pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
void
pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence__destroy(pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence * array);

/// Check for action/MoveToPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence__are_equal(const pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence * lhs, const pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/MoveToPose messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pose_traj_controller
bool
pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence__copy(
  const pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence * input,
  pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // POSE_TRAJ_CONTROLLER__ACTION__DETAIL__MOVE_TO_POSE__FUNCTIONS_H_
