cmake_minimum_required(VERSION 3.17)
project(test)

set(CMAKE_CXX_STANDARD 14)

set(BOOST_ROOT "/usr/local/include/boost")

include_directories(/usr/local/include) # 添加头文件搜索路径

link_directories(/usr/local/lib) # 添加库文件搜索路径

aux_source_directory(. DIR_SRCS)

add_executable(test ${DIR_SRCS})
