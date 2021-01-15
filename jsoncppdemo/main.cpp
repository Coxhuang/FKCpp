#include <iostream>
#include <sstream>
#include <iomanip>
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


int main() {
//    std::cout << "Hello, World!" << std::endl;
//    Json::Reader reader;
//    Json::Value value;
//    Json::Value value2;
//    Json::Value value3;
//    value2["11"] = "111";
//    value["1"] = 1;
//    value["2"] = value2;
//    value["3"] = value3;
//
//    func2(&value);

//    Json::FastWriter writer;
//    const std::string json_file = writer.write(value);
//    std::cout << json_file << std::endl;

    Json::Value arrayObj;
    Json::Value item;
//    for (int i=0; i<10; i++)
//    {
//        arrayObj.append(i);
//    }
//    arrayObj.append(1);
//    item[1].append(1);
    item.append(0);
    item.append(0);
    item.clear();
    Json::FastWriter writer;
    const std::string json_filea = writer.write(item);
    std::cout << json_filea << std::endl;


    Json::Value root;
    root["map_name"] = "test";
    root["position_name"] = "test1";

//    Json::StreamWriterBuilder writerBuilder;
//    std::unique_ptr<Json::StreamWriter> json_write(writerBuilder.newStreamWriter());
//    std::ostringstream ss;
//    json_write->write(root, &ss);
//    std::string data = ss.str();
//    std::string strContent = ss.str();

    std::string strJson1 = writer.write(root);

    std::cout << strJson1 << std::endl;


    double a = 0.87520803892910404;
    std::cout << a <<std::endl;
    std::cout << std::to_string(a) <<std::endl;

    std::stringstream ss;
    ss << std::setprecision(15) << a;
    std::cout << ss.str() <<std::endl;

    std::string oooo = "1cdcdcd";

    std::cout << "----------: " << oooo.rfind("\\n") << std::endl;

    double d = 1;
    std::cout << d << std::endl;

    if (d == 0) {
        std::cout << "00000" << std::endl;
    }

    Json::Value v15;
    v15.resize(0); // 构造空数组 []
    fmt_jsoncpp(v15);

    return 0;
}
