cmake_minimum_required(VERSION 3.17)
project(FSMDemo)

set(CMAKE_CXX_STANDARD 14)

add_library(hsmlibrary tbs_hsm.cc)
include_directories(hsm/include)

add_executable(FSMDemo main.cpp)

target_link_libraries(FSMDemo hsmlibrary)
