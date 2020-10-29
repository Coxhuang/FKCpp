//
// Created by Cox on 2020/9/29.
//

#ifndef INC_5_MY__EXPLICIT_PAT_H
#define INC_5_MY__EXPLICIT_PAT_H

#include <iostream>

class MyPat{
public:
    int age;
    int get_name(std::string name);
    MyPat() = default;
    MyPat(int a);
    explicit MyPat(const char *p);
    MyPat(const MyPat &obj);
    ~MyPat();
};

#endif //INC_5_MY__EXPLICIT_PAT_H
