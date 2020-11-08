cmake_minimum_required(VERSION 3.17)

project(trunk_thread)

set(CMAKE_CXX_STANDARD 14)

add_library(threadlibrary thread.cc) # 1/2

add_executable(tthread main.cc)

target_link_libraries(tthread threadlibrary) # 2/2




