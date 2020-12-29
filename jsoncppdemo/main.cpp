#include <iostream>
#include "json/json.h"
#include <stdio.h>



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
//    arrayObj.clear();
    Json::FastWriter writer;
//    const std::string json_file = writer.write(arrayObj);
//    std::cout << json_file << std::endl;

    const std::string json_filea = writer.write(item);
    std::cout << json_filea << std::endl;


    Json::Value root;
    root["map_name"] = "test";
    root["position_name"] = "test1";

    Json::StreamWriterBuilder writerBuilder;
    std::unique_ptr<Json::StreamWriter> json_write(writerBuilder.newStreamWriter());
    std::ostringstream ss;
    json_write->write(root, &ss);
    std::string data = ss.str();
//    std::string strContent = ss.str();
    std::cout << data << std::endl;





    return 0;
}
