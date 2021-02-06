#include <iostream>
#include "yaml-cpp/yaml.h"

int main() {
    YAML::Node config = YAML::LoadFile("../config.yaml");
    std::cout << "name:" << config["name"].as<std::string>() << std::endl;
    std::cout << "sex:" << config["sex"].as<std::string>() << std::endl;
    std::cout << "age:" << config["age"].as<int>() << std::endl;

    for (auto foo : config["skills"]) {
        std::cout << foo.first.as<std::string>() << ":" << foo.second.as<bool>() << std::endl;
    }

    return 0;
}
