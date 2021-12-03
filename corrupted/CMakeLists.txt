project(corrupted)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

find_package(Threads REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB REQUIRED glib-2.0)

add_executable(corrupted-pthread corrupted-pthread.cpp)
add_executable(corrupted-gloop corrupted-gloop.cpp)
add_library(dl-pthread SHARED dl-pthread.cpp)
add_library(dl-gloop SHARED dl-gloop.cpp)

target_link_libraries(corrupted-pthread PRIVATE ${CMAKE_DL_LIBS})
target_link_libraries(corrupted-gloop PRIVATE ${CMAKE_DL_LIBS})
target_link_libraries(dl-pthread PRIVATE Threads::Threads)

target_include_directories(dl-gloop PRIVATE ${GLIB_INCLUDE_DIRS})

target_link_libraries(dl-gloop PRIVATE ${GLIB_LDFLAGS})

install(TARGETS DESTINATION bin)
