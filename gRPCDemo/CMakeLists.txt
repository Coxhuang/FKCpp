cmake_minimum_required(VERSION 3.17)
project(gRPCDemo)

set(CMAKE_CXX_STANDARD 14)

#find_program(GRPC_CPP_PLUGIN grpc_cpp_plugin)
#find_package(PkgConfig REQUIRED)
#pkg_search_module(GRPC REQUIRED grpc)
#pkg_search_module(GRPCPP REQUIRED grpc++)
#list(APPEND LIGHTSTEP_LINK_LIBRARIES ${GRPCPP_LDFLAGS} ${GRPC_LDFLAGS})
#include_directories(SYSTEM ${GRPC_INCLUDE_DIRS} ${GRPCPP_INCLUDE_DIRS})

#find_package(Protobuf REQUIRED)
#if(PROTOBUF_FOUND)
#    message(STATUS "protobuf library found")
#else()
#    message(FATAL_ERROR "protobuf library is needed but cant be found")
#endif()
#
#INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
#PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS files/helloworld.proto)


# 查找 protobuf
find_package(Protobuf REQUIRED)
if (PROTOBUF_FOUND)
    message("protobuf found")
else ()
    message(FATAL_ERROR "Cannot find Protobuf")
endif ()

## 编译 proto 为 .cpp 和 .h
set(PROTO_FILES files/helloworld.proto)
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})
message("PROTO_SRCS = ${PROTO_SRCS}")
message("PROTO_HDRS = ${PROTO_HDRS}")
message("${PROJECT_NAME}")
#
## 关联 protobuf 到最后的二进制文件
add_executable(cmake_protobuf
        main.cpp
        ${PROTO_SRCS}
        ${PROTO_HDRS})
target_include_directories(cmake_protobuf
        PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC ${PROTOBUF_INCLUDE_DIRS}
    )
#
#
##link_directories(/usr/local/lib)
#
#add_executable(gRPCDemoexe main.cpp ${SRC_LIST} ${PROTO_SRCS} ${PROTO_HDRS})
#
#target_link_libraries(${PROJECT_NAME} ${PROTOBUF_LIBRARIES})


#cmake_minimum_required(VERSION 3.5.1)
#project(cmake_protobuf)
#
## Find protobuf
#find_package(Protobuf REQUIRED)
#if (PROTOBUF_FOUND)
#    message("protobuf found")
#else ()
#    message(FATAL_ERROR "Cannot find Protobuf")
#endif ()
#
## Compile the .proto file into .cpp and .h file
#set(PROTO_FILES proto/test.proto)
#PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})
#message("PROTO_SRCS = ${PROTO_SRCS}")
#message("PROTO_HDRS = ${PROTO_HDRS}")
#
#set(CMAKE_CXX_STANDARD 11)
#
#include_directories(${PROJECT_SOURCE_DIR}/include)
#include_directories(${PROJECT_SOURCE_DIR}/src)
#
#set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -ffunction-sections -O0")
#
#add_executable(cmake_protobuf
#        src/person.cpp
#        src/main.cpp
#
#        ${PROTO_SRCS}
#        ${PROTO_HDRS})
#
## Include dependent
#target_include_directories(${PROJECT_NAME}
#        PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
#        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
#        PUBLIC ${PROTOBUF_INCLUDE_DIRS})
#
## Library dependent
#target_link_libraries(${PROJECT_NAME} ${PROTOBUF_LIBRARIES})


