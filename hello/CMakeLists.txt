cmake_minimum_required(VERSION 3.0.2)
project(hello)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)


catkin_package()

include_directories(

  ${catkin_INCLUDE_DIRS}
)

 add_executable(pub_sub1 src/pub_sub1.cpp)
target_link_libraries(pub_sub1
   ${catkin_LIBRARIES}
 )
 add_executable(pub_sub2 src/pub_sub2.cpp)
target_link_libraries(pub_sub2
   ${catkin_LIBRARIES}
 )

