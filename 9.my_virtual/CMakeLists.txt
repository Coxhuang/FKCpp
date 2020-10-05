cmake_minimum_required(VERSION 3.17)
project(9_my_virtual)

add_subdirectory(home)

set(CMAKE_CXX_STANDARD 14)

add_executable(9_my_virtual main.cpp)

target_link_libraries(9_my_virtual MyPatFunc) # 不能放到 add_executable 前面
