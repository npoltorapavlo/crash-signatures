project(__cxa_pure_virtual)

cmake_minimum_required(VERSION 3.0)

add_executable(${PROJECT_NAME} __cxa_pure_virtual.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED YES)

install(TARGETS DESTINATION bin)
