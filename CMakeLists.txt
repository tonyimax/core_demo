cmake_minimum_required(VERSION 3.31)
project(core_demo)

set(CMAKE_CXX_STANDARD 20)

link_directories(../../core/cmake-build-debug)
link_libraries(core)
add_executable(core_demo main.cpp)
target_link_libraries(core_demo core)
