cmake_minimum_required(VERSION 3.17)

project(grpcdemo)

set(CMAKE_CXX_STANDARD 14)

find_package(Protobuf REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GRPCPP REQUIRED grpc++>=1.22.0)

include_directories(
        ${GRPCPP_INCLUDE_DIRS} # /usr/local/Cellar/grpc/1.29.1/include
        ${Protobuf_INCLUDE_DIRS} # /usr/local/include
)

link_directories(
        ${GRPCPP_LIBRARY_DIRS}
)


add_library(hellolibrary ../protos/helloworld.grpc.pb.cc ../protos/helloworld.pb.cc )

target_link_libraries(hellolibrary
        protobuf::libprotobuf # 将protobuf加到hellolibrary, 因为在hellolibrary 使用了protobuf
        )

add_executable(server_bin main.cpp)

target_link_libraries(server_bin
        ${GRPCPP_LIBRARIES}
        hellolibrary
        )