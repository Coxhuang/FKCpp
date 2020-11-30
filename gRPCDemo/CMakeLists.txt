cmake_minimum_required(VERSION 3.17)

project(grpcdemo)

set(CMAKE_CXX_STANDARD 14)

find_package(Protobuf REQUIRED)

set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GRPCPP REQUIRED grpc++>=1.22.0)

include_directories(
        ${GRPCPP_INCLUDE_DIRS}
        ${Protobuf_INCLUDE_DIRS}
)

link_directories(
        ${GRPCPP_LIBRARY_DIRS}
)


add_library(hellolibrary protos/helloworld.grpc.pb.cc protos/helloworld.pb.cc )

add_executable(hello_bin main.cpp)

target_link_libraries(hello_bin
        ${GRPCPP_LIBRARIES}
        ${_PROTOBUF_LIBPROTOBUF}
        hellolibrary
        )


