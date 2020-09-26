//
// Created by Cox on 2020/9/25.
//
#include <iostream>
#include "square/square_func.h"


using namespace std;

int main(){
    SquareCls square_obj(10);
    int ret = square_obj.square(2);
    square_obj.n = 9;
    cout << square_obj.n << ret;
    return 0;
}

