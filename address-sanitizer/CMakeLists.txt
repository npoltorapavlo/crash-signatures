project(address-sanitizer)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME} address-sanitizer.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fsanitize=address")

install(TARGETS DESTINATION bin)
