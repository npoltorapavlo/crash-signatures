cmake_minimum_required(VERSION 3.3)

project(crash-samples)

message("Building for '${CMAKE_SYSTEM_PROCESSOR}'")
if (CMAKE_SYSTEM_PROCESSOR MATCHES "^arm" OR
        CMAKE_SYSTEM_PROCESSOR MATCHES "^aarch64" OR
        CMAKE_SYSTEM_PROCESSOR MATCHES "^mips")
    set(BUILD_YOCTO 1)
endif ()

option(destructed-twice "Include destructed-twice." ON)
option(global-qthread "Include global-qthread." OFF) #TODO
option(corrupt-stack "Include corrupt-stack." ON)
option(quit-gmain-loop "Include quit-gmain-loop." ON)
option(rfcapi-test "Include rfcapi-test." ON)
option(thread-terminate "Include thread-terminate." ON)

if(destructed-twice)
    add_subdirectory(destructed-twice)
endif()
if(global-qthread)
    if(BUILD_YOCTO)
        add_subdirectory(global-qthread)
    endif()
endif()
if(corrupt-stack)
    add_subdirectory(corrupt-stack)
endif()
if(quit-gmain-loop)
    if(UNIX AND NOT APPLE) # TODO
        add_subdirectory(quit-gmain-loop)
    endif()
endif()
if(rfcapi-test)
    if(BUILD_YOCTO)
        add_subdirectory(rfcapi-test)
    endif()
endif()
if(thread-terminate)
    if(UNIX AND NOT APPLE) # TODO
        add_subdirectory(thread-terminate)
    endif()
endif()
