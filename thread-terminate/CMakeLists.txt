project(thread-terminate)
cmake_minimum_required(VERSION 3.8)

set(TARGET ${PROJECT_NAME})
set(TARGET_FRAMEWORK ${PROJECT_NAME}-framework)
set(TARGET_PLUGIN ${PROJECT_NAME}-plugin)

find_package(Threads REQUIRED)
find_package(PkgConfig REQUIRED)

add_executable(${TARGET} thread-terminate.c)
set_target_properties(${TARGET} PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES)
target_link_libraries(${TARGET} PRIVATE
        ${CMAKE_DL_LIBS})

add_library(${TARGET_FRAMEWORK} SHARED framework.c)
set_target_properties(${TARGET_FRAMEWORK} PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES)
target_link_libraries(${TARGET_FRAMEWORK} PRIVATE
        ${CMAKE_DL_LIBS})

add_library(${TARGET_PLUGIN} SHARED plugin.c pluginThread.cpp)
set_target_properties(${TARGET_PLUGIN} PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES)
target_link_libraries(${TARGET_PLUGIN} PRIVATE
        ${CMAKE_DL_LIBS} Threads::Threads)

install(TARGETS ${TARGET} ${TARGET_FRAMEWORK} ${TARGET_PLUGIN} DESTINATION bin)
