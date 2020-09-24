#cmake_minimum_required(VERSION 3.16) # CMake 最低版本号要求
#
#project(demo_project) # 工程信息
#
#aux_source_directory(. DIR_SRCS)
#
#add_executable(Project1 ${DIR_SRCS})

cmake_minimum_required(VERSION 3.16) # CMake 最低版本号要求

project(demo_project3) # 工程信息

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 添加 math 子目录
add_subdirectory(math)

# 指定生成目标
add_executable(Project3 main.cpp)

# 添加链接库
target_link_libraries(Project3 MathFunctions)


