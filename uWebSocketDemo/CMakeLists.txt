cmake_minimum_required(VERSION 3.17)
project(uWebSocketDemo)

set(CMAKE_CXX_STANDARD 14)

#include_directories(/home/trunk/uWebSockets/src)
include_directories(/usr/include/)

find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)

find_path(LIBUV_INCLUDE_DIR uv.h)
find_library(LIBUV_LIBRARY NAMES uv uv1)

add_executable(uWebSocketDemo main.cpp)


#target_link_libraries(uWebSocketDemo /usr/lib/libuWS.so)
