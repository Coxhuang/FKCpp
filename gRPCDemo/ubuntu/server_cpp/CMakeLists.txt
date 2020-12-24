cmake_minimum_required(VERSION 3.17)

project(grpcdemo)

set(CMAKE_CXX_STANDARD 14)

find_package(Threads)
find_package(protobuf REQUIRED)

find_package(gRPC REQUIRED)

include_directories(
        ${Protobuf_INCLUDE_DIRS}
)

add_library(hellolibrary ../protos/helloworld.grpc.pb.cc ../protos/helloworld.pb.cc )

target_link_libraries(hellolibrary
        protobuf::libprotobuf
        )

add_executable(server_bin main.cpp)

target_link_libraries(server_bin
        gRPC::grpc++
        hellolibrary
    )


