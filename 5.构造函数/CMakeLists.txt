cmake_minimum_required(VERSION 3.17)
project(demo5)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(home)

add_executable(demo5 main.cpp)

target_link_libraries(demo5 MyPatFunc) # 不能放到 add_executable 前面
