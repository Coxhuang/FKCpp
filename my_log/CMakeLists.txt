cmake_minimum_required(VERSION 3.17)
project(my_log)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_library(tlog SHARED tlog/tlog.cc)

add_executable(my_log main.cpp)

target_link_libraries(my_log tlog)