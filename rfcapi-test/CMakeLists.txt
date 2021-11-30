project(rfcapi-test)

cmake_minimum_required(VERSION 3.8)

set(TARGET ${PROJECT_NAME})

add_executable(${TARGET}
        rfcapi-test.cpp
        rfcutils.cpp
        textgen.cpp
        )

find_path(WDMP_INCLUDE_DIRS NAMES wdmp-c.h PATH_SUFFIXES wdmp-c)
target_include_directories(${TARGET} PRIVATE ${WDMP_INCLUDE_DIRS})

target_link_libraries(${TARGET} PRIVATE rfcapi)

set_target_properties(${TARGET} PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        )

install(TARGETS ${TARGET} DESTINATION bin)
