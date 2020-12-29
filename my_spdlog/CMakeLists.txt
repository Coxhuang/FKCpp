cmake_minimum_required(VERSION 3.17)
project(my_spdlog)

set(CMAKE_CXX_STANDARD 14)

include_directories(tlog/include)

add_executable(my_spdlog main.cpp tlog/src/tlog.cc tlog/src/tlog.h)