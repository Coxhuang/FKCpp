cmake_minimum_required(VERSION 3.17)
project(fmt_demo)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/include) # 添加头文件搜索路径

link_directories(/usr/local/lib) # 添加库文件搜索路径

add_executable(fmt_demo main.cpp)

target_link_libraries(fmt_demo fmt)

