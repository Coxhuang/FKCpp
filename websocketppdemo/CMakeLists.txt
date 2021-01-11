cmake_minimum_required(VERSION 3.17)
project(websocketppdemo)

set(CMAKE_CXX_STANDARD 14)



include_directories(include)

find_package (Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

link_directories (
        ${Boost_LIBRARY_DIRS}
)

add_executable(websocketppdemo main.cpp )

target_link_libraries(websocketppdemo
        ${Boost_LIBRARIES}
    )