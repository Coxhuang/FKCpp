cmake_minimum_required(VERSION 3.17)
project(wsppdemo)

set(CMAKE_CXX_STANDARD 14)

set(BOOST_ROOT "/usr/local/include/boost")
set(BOOSTROOT "/usr/local/include/boost")
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

FIND_PACKAGE(Threads REQUIRED)
SET(Boost_USE_MULTITHREADED ON)

find_package(Boost REQUIRED COMPONENTS system)


add_executable(wsppdemo main.cpp)

target_link_libraries(wsppdemo boost_thread boost_system ${CMAKE_THREAD_LIBS_INIT})


