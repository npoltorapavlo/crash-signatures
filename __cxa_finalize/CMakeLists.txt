project(__cxa_finalize)

cmake_minimum_required(VERSION 3.8)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_executable(${PROJECT_NAME} __cxa_finalize.cpp)

add_library(dl1 STATIC dl1.cpp)
add_library(dl2 SHARED dl2.cpp)
add_library(dl3 SHARED dl3.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE dl2 dl3)
target_link_libraries(dl2 PRIVATE dl1)
target_link_libraries(dl3 PRIVATE dl1)

install(TARGETS DESTINATION bin)
