project(missing-return-statement)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

add_executable(missing-return-statement missing-return-statement.cpp)

install(TARGETS DESTINATION bin)
