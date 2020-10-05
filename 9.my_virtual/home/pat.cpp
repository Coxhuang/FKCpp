//
// Created by Cox on 2020/10/5.
//
#include "pat.h"
#include <iostream>

using namespace std;

int MyPat::eat() {

    cout << "基类 eat()" << endl;

    return 0;
}

MyPat::MyPat(){
    cout << "基类 构造函数 无参数" << endl;
}

MyPat::MyPat(int a) {
    cout << "基类 构造函数 一个参数" << endl;
}

MyPat::MyPat(MyPat &) {
    cout << "基类 复制构造函数" << endl;
};


int Dog::eat() {

    cout << "Dog类 eat()" << endl;

    return 0;
}

int Cat::eat() {

    cout << "Cat类 eat()" << endl;

    return 0;
}
