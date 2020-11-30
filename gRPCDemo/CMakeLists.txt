cmake_minimum_required(VERSION 3.17)

project(grpcdemo)

set(CMAKE_CXX_STANDARD 14)

find_package(Protobuf REQUIRED)
message(STATUS "Using protobuf ${Protobuf_VERSION}")

set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)


find_package(PkgConfig REQUIRED)
pkg_check_modules(GRPCPP REQUIRED grpc++>=1.22.0)
# gRPC
message(STATUS "Using gRPC ${GRPC_VERSION}")

include_directories(
        # ${GRPC_INCLUDE_DIRS}
        ${GRPCPP_INCLUDE_DIRS}
        ${Protobuf_INCLUDE_DIRS}
)

link_directories(
        ${GRPCPP_LIBRARY_DIRS}
)


add_library(hsmlibrary protos/mathtest.grpc.pb.cc protos/mathtest.pb.cc )

add_executable(program main.cpp)

target_link_libraries(program
        ${GRPCPP_LIBRARIES}
        ${_PROTOBUF_LIBPROTOBUF}
        hsmlibrary
        )


