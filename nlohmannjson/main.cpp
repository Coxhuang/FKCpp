#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

int main() {
    nlohmann::json value;

    // 1. 赋值
    value["id"] = 1;
    value["name"] = "cox";
    value["is_male"] = true;
    std::cout << value << std::endl; // {"id":1,"is_male":true,"name":"cox"}

    // 2. 读取
    std::cout << value["id"].get<int>() << std::endl; // 1
    std::cout << value["name"].get<std::string>() << std::endl; // cox
    std::cout << value["is_male"].get<bool>() << std::endl; // 1

    // 3. 读取文件
    nlohmann::json fv;
    std::ifstream jfile("../haha.json");
    jfile >> fv; // 以文件流形式读取 json 文件
    std::cout  << fv.at("is_male") << std::endl; // true

    // 4. 数组
    nlohmann::json v4;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            v4[i][j] = i+j;
        }
    }
    std::cout << "v4:" << v4 << std::endl; // [[0,1,2],[1,2,3],[2,3,4],[3,4,5],[4,5,6]]

    // 5. STD转json
    std::vector<int> int_vector{1, 2, 3, 4};
    nlohmann::json v5_1(int_vector);
    std::cout << "v5_1:" << v5_1 << std::endl; // [1,2,3,4]

    std::map<std::string, int> c_map { {"one", 1}, {"two", 2}, {"three", 3} };
    nlohmann::json v5_2(c_map);
    std::cout << "v5_2:" << v5_2 << std::endl; // {"one":1,"three":3,"two":2}


    return 0;
}
