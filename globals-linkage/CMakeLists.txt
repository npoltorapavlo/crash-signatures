project(globals-linkage)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME} globals-linkage.cpp)

add_library(dl5 SHARED dl5.cpp)
add_library(dl6 SHARED dl6.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE dl5 dl6)

install(TARGETS DESTINATION bin)
