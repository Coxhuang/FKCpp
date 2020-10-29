#include <iostream>
#include "home/pat.h"

MyPat func()
{
    MyPat a(1);
    return a;
}


int main() {
//    MyPat pat{2}; // 一般构造函数
//    MyPat pat1 = pat; // 一般构造函数

    func();

//    std::cout<<"*****************"<<std::endl;
//
//    MyPat b(2);
//    MyPat c = a;
//    b=func();

    return 0;
}
