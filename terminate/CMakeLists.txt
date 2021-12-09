project(terminate)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

find_package(Threads REQUIRED)

add_executable(terminate-thread terminate-thread.cpp)
add_executable(terminate-thread-detach terminate-thread-detach.cpp)
add_executable(terminate-throw terminate-throw.cpp)
add_executable(terminate-throw-destructor terminate-throw-noexcept.cpp)
add_executable(terminate-throw-stack-unwinding terminate-throw-stack-unwinding.cpp)

target_link_libraries(terminate-thread PRIVATE Threads::Threads)
target_link_libraries(terminate-thread-detach PRIVATE Threads::Threads)

install(TARGETS DESTINATION bin)
