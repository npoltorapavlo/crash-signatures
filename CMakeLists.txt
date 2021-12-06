cmake_minimum_required(VERSION 3.3)

project(crash-samples)

message("Building for '${CMAKE_SYSTEM_PROCESSOR}'")
if (CMAKE_SYSTEM_PROCESSOR MATCHES "^arm" OR
        CMAKE_SYSTEM_PROCESSOR MATCHES "^aarch64" OR
        CMAKE_SYSTEM_PROCESSOR MATCHES "^mips")
    set(BUILD_YOCTO 1)
endif ()

option(corrupted "Include corrupted." ON)
option(__cxa_pure_virtual "Include __cxa_pure_virtual." ON)
option(terminate "Include terminate." ON)

if(corrupted)
    add_subdirectory(corrupted)
endif()
if(__cxa_pure_virtual)
    add_subdirectory(__cxa_pure_virtual)
endif()
if(terminate)
    add_subdirectory(terminate)
endif()
