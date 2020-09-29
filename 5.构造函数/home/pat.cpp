//
// Created by Cox on 2020/9/27.
//
#include "iostream"
#include "pat.h"

using namespace std;

// 无参数构造函数
// 如果创建一个类你没有写任何构造函数,则系统会自动生成默认的无参构造函数，函数为空，什么都不做
// 只要你写了一个下面的某一种构造函数，系统就不会再自动生成这样一个默认的构造函数，如果希望有一个这样的无参构造函数，则需要自己显示地写出来
MyPat::MyPat(void) {
    age = 1;
    char a = '1';
    string b = "92x";
    std::cout << "构造函数 void: " << age << a << b << endl;
}

// 一般构造函数（也称重载构造函数）
// 一般构造函数可以有各种参数形式,一个类可以有多个一般构造函数，前提是参数的个数或者类型不同（基于c++的重载函数原理）
// 例如：你还可以写一个 MyPat(int num1, int num2)的构造函数出来
// 创建对象时根据传入的参数不同调用不同的构造函数
MyPat::MyPat(int a) {
    age = a;
    std::cout << "构造函数 int: " << age << endl;
}

MyPat::MyPat(char a) {
    std::cout << "构造函数 char: " << a << endl;
}

MyPat::MyPat(char *a) {
    std::cout << "构造函数 string: " << a << endl;
}


