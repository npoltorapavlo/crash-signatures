project(race-condition)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

find_package(Threads REQUIRED)

add_executable(race-condition-assignment race-condition-assignment.cpp)

target_link_libraries(race-condition-assignment PRIVATE Threads::Threads)

install(TARGETS DESTINATION bin)
