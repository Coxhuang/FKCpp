#include <iostream>
#include <vector>
#include <map>
#include "tprint.hpp"
#include "cache.hpp"

using namespace trunk::tools::tprint;
using namespace trunk::tools::tcache;

int main( int argc, char * argv[] ){
//    std::map<std::string, size_t> people{{"Ann", 25}, {"Bill", 46},{"Jack", 32},{"Jill", 32}};
//    std::map<std::string,size_t> people{std::make_pair("Ann",1),std::make_pair("Bill", 46),std::make_pair("Jack", 32),std::make_pair("Jill", 32)};
//    print_map<std::string, size_t>(people);
//    auto value = people.at("Ann");
//    std:: cout << "value: " << value << std:: endl;
//    auto iter = people.find("Bill");
//    std:: cout << "find: " << iter->first << std:: endl;
//    auto iter = people.find ("Ann");
//    if (iter != std::end(people)){
//        std:: cout << "找到" << std:: endl;
//    }
//    std::map<int,std::string> student;
//    std::vector<int> student(5,2);
//    print_vector<int>(student);

    TrunkCache c;
    std::cout << "x: " << TrunkCache::a << std::endl;


    return 0;
}
