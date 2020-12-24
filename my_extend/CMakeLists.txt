cmake_minimum_required(VERSION 3.17)
project(my_extend)

set(CMAKE_CXX_STANDARD 14)

#add_library(src/a/a.cc )

add_executable(my_extend main.cpp src/b/b.cc src/a/a.cc )