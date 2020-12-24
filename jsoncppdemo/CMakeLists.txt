cmake_minimum_required(VERSION 3.17)
project(jsoncppdemo)

set(CMAKE_CXX_STANDARD 14)

#include_directiories(/usr/include/curl) # 头文件
#target_link_libraries(myprogram path/curl.so) # 库文件


include_directories("/usr/local/include")

add_executable(jsoncppdemo main.cpp)

target_link_libraries(jsoncppdemo "/usr/local/lib/libjsoncpp.dylib")

