project(M_realloc_insert)

cmake_minimum_required(VERSION 3.3)

set(TARGET ${PROJECT_NAME})

add_executable(${TARGET}
        M_realloc_insert.cpp
        )

set_target_properties(${TARGET} PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        )

install(TARGETS ${TARGET} DESTINATION bin)
