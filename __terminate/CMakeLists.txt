project(__terminate)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

find_package(Threads REQUIRED)

add_executable(__terminate-thread __terminate-thread.cpp)
add_executable(__terminate-thread-detach __terminate-thread-detach.cpp)
add_executable(__terminate-throw __terminate-throw.cpp)

target_link_libraries(__terminate-thread PRIVATE Threads::Threads)
target_link_libraries(__terminate-thread-detach PRIVATE Threads::Threads)

install(TARGETS DESTINATION bin)
