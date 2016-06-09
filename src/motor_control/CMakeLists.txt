cmake_minimum_required(VERSION 2.8.3)
project(motor_control)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  serial
  message_generation
)

add_message_files(
   FILES
   #comand_msg.msg
   comand_msg_1.msg
   jointState.msg
)

generate_messages(
   DEPENDENCIES
   std_msgs
)

catkin_package(
 INCLUDE_DIRS include
 CATKIN_DEPENDS roscpp std_msgs message_runtime
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(motor_control src/motor_control.cpp)
target_link_libraries(motor_control ${catkin_LIBRARIES})
add_dependencies(motor_control motor_control_generate_messages_cpp)

add_executable(motor_comandor src/motor_comandor.cpp)
target_link_libraries(motor_comandor ${catkin_LIBRARIES})
add_dependencies(motor_comandor motor_control_generate_messages_cpp)
