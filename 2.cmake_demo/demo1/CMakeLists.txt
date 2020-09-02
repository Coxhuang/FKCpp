# CMake 最低版本号要求, 指定运行此配置文件所需的 CMake 的最低版本
cmake_minimum_required(VERSION 3.16)

# 项目信息, 表示项目的名称是 demo
project(demo)

set(CMAKE_CXX_STANDARD 11)

# 指定生成目标, 将名为 main.cpp 的源文件编译成一个名称为 demo_exe 的可执行文件
add_executable(demo_exe main.cpp)