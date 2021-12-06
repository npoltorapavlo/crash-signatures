project(double-free)
cmake_minimum_required(VERSION 3.8)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_executable(double-free-global double-free-global.cpp)

add_library(double-free-dl1 STATIC double-free-dl1.cpp)

add_library(double-free-dl2 SHARED double-free-dl2.cpp)
add_library(double-free-dl3 SHARED double-free-dl3.cpp)

target_link_libraries(double-free-global PRIVATE double-free-dl2 double-free-dl3)

target_link_libraries(double-free-dl2 PRIVATE double-free-dl1)
target_link_libraries(double-free-dl3 PRIVATE double-free-dl1)

install(TARGETS DESTINATION bin)
