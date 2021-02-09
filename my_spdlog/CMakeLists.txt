cmake_minimum_required(VERSION 3.17)
project(my_spdlog)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(my_spdlog main.cpp)