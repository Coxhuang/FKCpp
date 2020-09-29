cmake_minimum_required(VERSION 3.17)
project(5_my__explicit)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(home)

add_executable(5_my__explicit main.cpp)

target_link_libraries(5_my__explicit MyPatFunc) # 不能放到 add_executable 前面
