project(corrupted)

cmake_minimum_required(VERSION 3.0)

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} corrupted.cpp)
add_library(dl4 SHARED dl4.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_DL_LIBS})
target_link_libraries(dl4 PRIVATE Threads::Threads)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED YES)

install(TARGETS DESTINATION bin)
