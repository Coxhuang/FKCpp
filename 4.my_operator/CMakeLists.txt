cmake_minimum_required(VERSION 3.16) # CMake 最低版本号要求

project(test_operator)

aux_source_directory(. DIR_SRCS)

add_executable(operator_exe main.cpp)

