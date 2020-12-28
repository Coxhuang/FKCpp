cmake_minimum_required(VERSION 3.17)
project(glog_demo)

set(CMAKE_CXX_STANDARD 14)


include_directories(/usr/local/Cellar/glog/0.4.0/include)
include_directories(/usr/local/Cellar/gflags/2.2.2/include)

find_package (glog 0.4.0 REQUIRED)

add_executable(glog_demo main.cpp)

target_link_libraries (glog_demo glog::glog)


