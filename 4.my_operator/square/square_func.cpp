//
// Created by Cox on 2020/9/25.
//
#include "square_func.h"
#include <iostream>


SquareCls::SquareCls() {
    std::cout << "构造函数"  << std::endl;
}

int SquareCls::square(int n) {
    return n*n;
}


