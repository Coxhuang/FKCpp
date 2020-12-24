cmake_minimum_required(VERSION 3.17)
project(py_cpp)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost COMPONENTS thread serialization python REQUIRED)

include_directories(${Boost_INCLUDE_DIR}
        /usr/include/python3.5)

add_executable(py_cpp main.cpp)

target_link_libraries(py_cpp
        ${Boost_LIBRARIES}
        /usr/lib/x86_64-linux-gnu/libboost_python-py35.so
        /usr/lib/x86_64-linux-gnu/libstdc++.so.6
        /usr/lib/x86_64-linux-gnu/libpython3.5m.so
        )
install(TARGETS py_cpp RUNTIME DESTINATION bin)

