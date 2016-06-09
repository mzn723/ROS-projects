cmake_minimum_required(VERSION 2.8.3)
project(pupil_tracker)

find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
  message_generation
)

add_message_files(
   FILES
   gaze_position.msg
)

generate_messages(
   DEPENDENCIES
   std_msgs
)

catkin_package(
  #INCLUDE_DIRS include
  LIBRARIES pupil_tracker
  CATKIN_DEPENDS rospy std_msgs message_runtime
  DEPENDS system_lib
)



include_directories(
  ${catkin_INCLUDE_DIRS}
)


