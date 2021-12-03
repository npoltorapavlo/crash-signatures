project(corrupted)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

find_package(Threads REQUIRED)

add_executable(corrupted corrupted.cpp)
add_library(dl1 SHARED dl1.cpp)

target_link_libraries(corrupted PRIVATE ${CMAKE_DL_LIBS})
target_link_libraries(dl1 PRIVATE Threads::Threads)

install(TARGETS DESTINATION bin)
