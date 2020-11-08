cmake_minimum_required(VERSION 3.17)
project(Tools)

set(CMAKE_CXX_STANDARD 14)

#add_library(threadlibrary utils/thread/thread.cc) # 1/2

add_executable(Tools main.cpp)

#target_link_libraries(Tools threadlibrary) # 2/2



