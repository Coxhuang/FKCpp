cmake_minimum_required(VERSION 3.17)
project(yaml_demo)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/include)

find_package (PkgConfig REQUIRED)
pkg_check_modules(YAMLCPP REQUIRED yaml-cpp) # 查找yaml-cpp

link_directories(
    ${YAMLCPP_LIBRARY_DIRS} # 添加yaml-cpp库文件路径
)

add_executable(yaml_demo main.cpp)

target_link_libraries(yaml_demo
    ${YAMLCPP_LIBRARIES} # 将yaml-cpp库连接到yaml_demo可执行文件中
)