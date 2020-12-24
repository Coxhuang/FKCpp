cmake_minimum_required(VERSION 3.17)
project(meventdemo)

set(CMAKE_CXX_STANDARD 14)

AUX_SOURCE_DIRECTORY(mevent DIR_SRCS)

add_executable(meventdemo main.cpp ${DIR_SRCS})



