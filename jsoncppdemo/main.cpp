#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include "json/json.h"
#include <stdio.h>
#include <cstring>
#include <string>



void func(Json::Value *t){
    Json::FastWriter writer;
    const std::string json_file = writer.write(*t);
    std::cout << json_file << std::endl;
}

void func2(Json::Value *t){
//    Json::FastWriter writer;
//    const std::string json_file = writer.write(*t);
//    std::cout << json_file << std::endl;
    func(t);
}

static void fmt_jsoncpp(Json::Value value){
    Json::FastWriter writer;
    const std::string json_string = writer.write(value);
    std::cout << json_string << std::endl;
}

void co() {
    Json::Value temp;
    std::vector<int> a(20,1);
    unsigned int i = 0;
    for (auto &foo : a) {
        std::cout << foo << std::endl;
        temp[i] = foo;
        i++;
    }
}


int main() {
//    std::cout << "Hello, World!" << std::endl;
    Json::Value value;
    value["11"] = "111";
    std::cout << value.get("111","").asString() << std::endl;
//    Json::Value value2;
//    Json::Value value3;
//    value2["11"] = "111";
//    value["1"] = 1;
//    value["2"] = value2;
//    value["3"] = value3;
//
//    func2(&value);

    Json::FastWriter writer;
    const std::string json_file = writer.write(value);
    std::cout << json_file << std::endl;

//    Json::Value arrayObj;
//    Json::Value item;
////    for (int i=0; i<10; i++)
////    {
////        arrayObj.append(i);
////    }
////    arrayObj.append(1);
////    item[1].append(1);
//    item.append(0);
//    item.append(0);
//    item.clear();
//    Json::FastWriter writer;
//    const std::string json_filea = writer.write(item);
//    std::cout << json_filea << std::endl;
//
//
//    Json::Value root;
//    root["map_name"] = "test";
//    root["position_name"] = "test1";
//
////    Json::StreamWriterBuilder writerBuilder;
////    std::unique_ptr<Json::StreamWriter> json_write(writerBuilder.newStreamWriter());
////    std::ostringstream ss;
////    json_write->write(root, &ss);
////    std::string data = ss.str();
////    std::string strContent = ss.str();
//
//    std::string strJson1 = writer.write(root);
//
//    std::cout << strJson1 << std::endl;
//    std::cout << root["map_name"] << std::endl;
//
//
//    double a = 0.87520803892910404;
//    std::cout << a <<std::endl;
//    std::cout << std::to_string(a) <<std::endl;
//
//    std::stringstream ss;
//    ss << std::setprecision(15) << a;
//    std::cout << ss.str() <<std::endl;
//
//    std::string oooo = "1cdcdcd";
//
//    std::cout << "----------: " << oooo.rfind("\\n") << std::endl;
//
//    double d = 1;
//    std::cout << d << std::endl;
//
//    if (d == 0) {
//        std::cout << "00000" << std::endl;
//    }
//
//    Json::Value v15;
//    v15.resize(0); // 构造空数组 []
//    fmt_jsoncpp(v15);
//
//    Json::Value v15_2;
//    v15_2["code"] = 20;
//
//    std::vector<int> v = {1,2,3};
//    std::vector<std::map<std::string, std::string>> v2;
//    v2 = {
//            {
//                    std::pair<std::string, std::string>("code","1"),
//                    std::pair<std::string, std::string>("text","2")
//            },
//            {
//                    std::pair<std::string, std::string>("code","3"),
//                    std::pair<std::string, std::string>("text","4")
//            }
//    };
//
//    std::cout << "1:" << v2[0].at("code")<< std::endl;
//    std::cout << "1:" << v2[1].at("code")<< std::endl;



//    for (int i = 0; i < 25; ++i) {
//        co();
//    }
//    std::cout << "------" << std::endl;

    const std::map<unsigned int, std::string> aaa = {
            std::pair<unsigned int, std::string>(0,"normal"),
            std::pair<unsigned int, std::string>(1,"stop_status")
    };




    return 0;
}
