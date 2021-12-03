project(global-qthread)

cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

list(APPEND CMAKE_PREFIX_PATH "/Users/npoltorapavlo/Qt/5.15.2/clang_64/lib/cmake/Qt5")
find_package(Qt5 COMPONENTS Core REQUIRED)

add_executable(global-qthread logger.cpp main.cpp signalhandler.cpp)

target_link_libraries(global-qthread Qt5::Core)

install(TARGETS DESTINATION bin)
