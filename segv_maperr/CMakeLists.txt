project(segv_maperr)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} segv_maperr.cpp)
add_library(dl4 SHARED dl4.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_DL_LIBS})
target_link_libraries(dl4 PRIVATE Threads::Threads)

install(TARGETS DESTINATION bin)
