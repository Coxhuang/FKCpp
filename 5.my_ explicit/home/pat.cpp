//
// Created by Cox on 2020/9/29.
//
#include "pat.h"
#include <iostream>

int MyPat::get_name(std::string name) {

    std::cout << name << std::endl;
    return 1;
}
//
//MyPat::MyPat() {
//    std::cout << "构造函数 x" << std::endl;
//}

MyPat::MyPat(int a) {
    std::cout << "构造函数 a" << a << std::endl;
}

MyPat::MyPat(const char *p) {
    std::cout << "构造函数 p" << *p << std::endl;
}

MyPat::MyPat(const MyPat &obj) {
    std::cout <<  "拷贝构造函数" << std::endl;

}
