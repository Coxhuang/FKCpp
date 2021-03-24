cmake_minimum_required(VERSION 3.17)
project(flanndemo)

set(CMAKE_CXX_STANDARD 14)

find_package ( PkgConfig REQUIRED )
pkg_check_modules(FLANN REQUIRED flann)
pkg_check_modules(NANOFLANN REQUIRED nanoflann)
pkg_check_modules(JSONCPP REQUIRED jsoncpp)

include_directories(${FLANN_INCLUDE_DIRS})
include_directories(${JSONCPP_INCLUDE_DIRS})

message(${FLANN_INCLUDE_DIRS}flann/io/)

link_directories (
        ${JSONCPP_LIBRARY_DIRS}
        ${FLANN_LIBRARY_DIRS}
        ${NANOFLANN_LIBRARY_DIRS}
)

add_executable(flanndemo main.cpp )

target_link_libraries(flanndemo
        ${JSONCPP_LIBRARIES}
        ${FLANN_LIBRARIES}
        ${NANOFLANN_LIBRARIES}
    )



