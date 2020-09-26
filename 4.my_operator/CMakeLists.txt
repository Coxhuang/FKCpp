cmake_minimum_required(VERSION 3.16) # CMake 最低版本号要求

project(square_demo)

aux_source_directory(. DIR_SRCS)

add_subdirectory(square)

add_executable(square_exe main.cpp)

target_link_libraries(square_exe SquareFunctions) # 不能放到 add_executable 前面





