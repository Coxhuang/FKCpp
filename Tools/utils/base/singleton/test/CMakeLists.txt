cmake_minimum_required(VERSION 3.17)
project(singleton)

set(CMAKE_CXX_STANDARD 14)

add_library(singletonlibrary singleton_test.cc) # 1/2

add_executable(singleton_exe test.cc)

target_link_libraries(singleton_exe singletonlibrary) # 2/2



