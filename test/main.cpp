#include <iostream>
#include <vector>
#include <map>
//#include "tprint.hpp"
//#include "cache.hpp"
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <iostream>
#include <ctime>
#include <time.h>
#include <thread>


//using namespace trunk::tools::tprint;
//using namespace trunk::tools::tcache;
#include<sstream>

std::string Convert(float Num)

{

    std::ostringstream oss;

    oss<<Num;

    std::string str(oss.str());

    return str;

}

int main( int argc, char * argv[] ){
//    std::map<std::string, size_t> people{{"Ann", 25}, {"Bill", 46},{"Jack", 32},{"Jill", 32}};
//    std::map<std::string,size_t> people{std::make_pair("Ann",1),std::make_pair("Bill", 46),std::make_pair("Jack", 32),std::make_pair("Jill", 32)};
//    print_map<std::string, size_t>(people);
//    auto value = people.at("Ann");
//    std:: cout << "value: " << value << std:: endl;
//    people["A2nn"] = 11;
//    auto value2 = people.at("A2nn");
//    std:: cout << "value2: " << value2 << std:: endl;
//    people["A2nn"] = 21;
//    auto value3 = people.at("A2nn");
//    std:: cout << "value3: " << value3 << std:: endl;
//
//    auto iter = people.find("Bill");
//    std:: cout << "find: " << iter->first << std:: endl;
//    auto iter = people.find ("Ann");
//    if (iter != std::end(people)){
//        std:: cout << "找到" << std:: endl;
//    }
//    std::map<int,std::string> student;
//    std::vector<int> student(5,2);
//    print_vector<int>(student);

//    TrunkCache c;
//    std::cout << "x: " << TrunkCache::a << std::endl;
//    std::vector<int> buffer(11,0);
//    std::vector<int> buffer2(1,1);
//
//    for (auto i : buffer){
//        std::cout << i;
//    }
//    for (auto i : buffer2){
//        std::cout << i;
//    }
//    buffer = buffer2;
//    for (auto i : buffer){
//        std::cout << i;
//    }
//    float tanValue1 = tan(45.0f);
//    std::cout<<"tan(45) = "<<tanValue1<<std::endl;
//    std::cout<<atan2(1,sqrt(3))*180/M_PI<<std::endl;// 30度 第一象限
//    std::cout<<atan2(1,sqrt(3))*180/M_PI<<std::endl;// 30度 第一象限

//    std::map<std::string , int> mymap{
//        std::pair<std::string, int>("a", 100),
//        std::pair<std::string, int>("b", 100)
//    };
//
//    for (const auto& i : mymap){
//        std::cout << i.first << ":" << i.second<< std::endl;
//    }

//    float ff = 125.456789;
//    ff = ((float) ((int) ((ff + 0.005) * 1000))) / 1000;
//    ff = int(ff*1000);
//    ff = round(ff * 1000) / 1000.0;

//    std::cout << std::fixed << ff << std::endl;
//    std::cout  << ff << typeid(ff).name() << std::endl;
//    std::cout  << Convert(ff) << std::endl;
//    std::string a=std::to_string(ff);
//
//    std::cout<<a<<std::endl;

//    std::string a;
//    a = "1";
//
//    if (a.empty()){
//        std::cout << "aaaa";
//    }

//    std::queue<std::string> port_queue; // 任务队列
//    port_queue.push("ppp");
//    std::cout << port_queue.empty();

////    time_t myt1=time(NULL);
//    std::cout<<"myt is :"<<time(NULL)<<std::endl;
//    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // 休眠
////    time_t myt2=time(NULL);
//    std::cout<<"myt is :"<<time(NULL)+3<<std::endl;

//    int p[20 * 20] = {-1};   // [0,100]
//
//    p[10] = 100;
    std::vector<signed char> a(200,-1);



    return 0;
}
