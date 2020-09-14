//
// Created by Cox on 2020/9/10.
//

#ifndef INC_3_CLASS_POINT_H
#define INC_3_CLASS_POINT_H

#include <iostream>
using namespace std;

class Point {

public:
    void set_point(int x, int y); // 声明
    void print_point() const ; // 声明

private:
    int xPos;
    int yPos;
};

void Point::set_point(int x, int y) { // 定义
    xPos = x;
    yPos = y;
}

void Point::print_point() const { // 定义
    std::cout<< "x = " << xPos << endl;
    cout<< "y = " << yPos << endl;
}

#endif //INC_3_CLASS_POINT_H
