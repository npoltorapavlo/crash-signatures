project(_M_realloc_insert)

cmake_minimum_required(VERSION 3.0)

add_executable(${PROJECT_NAME} _M_realloc_insert.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED YES)

install(TARGETS DESTINATION bin)
