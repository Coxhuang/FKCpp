cmake_minimum_required(VERSION 3.17)
project(websocketppdemo)

set(CMAKE_CXX_STANDARD 14)



include_directories(include)
find_package(PkgConfig REQUIRED)

find_package (Boost REQUIRED COMPONENTS system thread)
pkg_check_modules(JSONCPP jsoncpp)

include_directories(${JSONCPP_INCLUDE_DIRS}) # json 4/4

include_directories(${Boost_INCLUDE_DIRS})

link_directories (
        ${Boost_LIBRARY_DIRS}
        ${JSONCPP_LIBRARY_DIRS} # json 2/3
)

add_executable(websocketppdemo main.cpp )

target_link_libraries(websocketppdemo
        ${Boost_LIBRARIES}
        ${JSONCPP_LIBRARIES} # json 3/3
    )