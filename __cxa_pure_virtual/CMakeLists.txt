project(__cxa_pure_virtual)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

add_executable(__cxa_pure_virtual-deleted __cxa_pure_virtual-deleted.cpp)

install(TARGETS DESTINATION bin)
