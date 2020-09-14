cmake_minimum_required(VERSION 3.16)
project(Project)

set(CMAKE_CXX_STANDARD 14)

#add_executable(Project main.cpp)
aux_source_directory(. DIR_SRCS) # 当前目录所有源文件的文件名赋值给变量 DIR_SRCS

# 指定生成目标

add_executable(Project1 ${DIR_SRCS}) # 指示变量 DIR_SRCS 中的源文件需要编译成一个名称为 Demo 的可执行文件