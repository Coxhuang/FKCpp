cmake_minimum_required(VERSION 3.17)
project(flanndemo)

set(CMAKE_CXX_STANDARD 14)

find_package ( PkgConfig REQUIRED )
pkg_check_modules(FLANN REQUIRED flann)
pkg_check_modules(NANOFLANN REQUIRED nanoflann)

include_directories(${FLANN_INCLUDE_DIRS})
include_directories(${FLANN_INCLUDE_DIRS}/flann/io/)

message(${FLANN_INCLUDE_DIRS}flann/io/)

link_directories (
        ${FLANN_LIBRARY_DIRS}
        ${NANOFLANN_LIBRARY_DIRS}
)

add_executable(flanndemo main.cpp )

target_link_libraries(flanndemo
        ${FLANN_LIBRARIES}
        ${NANOFLANN_LIBRARIES}
    )



