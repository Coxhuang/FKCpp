cmake_minimum_required(VERSION 3.17)
project(nlohmann_demo)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/include)

find_package (PkgConfig REQUIRED)
pkg_check_modules(NLOHMANNJSON REQUIRED nlohmann_json) # 查找nlohmann_json

link_directories(
        ${NLOHMANNJSON_LIBRARY_DIRS} # 添加nlohmann_json库文件路径
)

add_executable(nlohmann_demo main.cpp)

target_link_libraries(nlohmann_demo
    ${NLOHMANNJSON_LIBRARIES} # 将nlohmannjson库连接到nlohmann_demo可执行文件中
)


