
cmake_minimum_required(VERSION 3.16) # CMake 最低版本号要求

project(demo_project) # 工程信息

set(CMAKE_CXX_STANDARD 14) # Cpp 标准: cpp14

add_executable(Project1 main.cpp MathFunctions.c) # 将名为 main.cpp MathFunctions.c 的源文件编译成一个名称为 Project1 的可执行文件