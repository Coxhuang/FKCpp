//
// Created by Cox on 2020/9/13.
//
#include <iostream>
//#include "config.h.in"
#include <config.h>

#ifdef USE_MYMATH
    #include <MathFunctions.h>
#else
    #include <math.h>
#endif

using namespace std;

int main(){

    double result = power(1, 0);
    std::cout << result;
    return 0;
}

