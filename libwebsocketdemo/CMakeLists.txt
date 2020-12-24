cmake_minimum_required(VERSION 3.17)
project(libwebsocketdemo)

set(CMAKE_CXX_STANDARD 14)

include_directories(/home/alex/CPP/lib/libwebsockets/include)

set(CMAKE_CXX_FLAGS "-w -pthread")

set(SF_SERVER server.cpp)

add_executable(libwebsocketdemo ${SF_SERVER})

target_link_libraries(libwebsocketdemo /home/alex/CPP/lib/libwebsockets/lib/libwebsockets.so)
