//
// Created by Cox on 2020/9/25.
//
#include "square_func.h"
#include <iostream>

int SquareCls::square(int a) {
    return a*a;
}

SquareCls::SquareCls(int a) {
    std::cout << a << std::endl;
}

