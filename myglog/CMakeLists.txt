cmake_minimum_required(VERSION 3.17)
project(myglog)

set(CMAKE_CXX_STANDARD 14)

find_package (glog 0.4.0 REQUIRED)

add_executable(myglog main.cpp)

target_link_libraries (myglog glog::glog)


