//
// Created by Cox on 2020/10/5.
//

#ifndef INC_9_MY_VIRTUAL_PAT_H
#define INC_9_MY_VIRTUAL_PAT_H

class MyPat{
public:
    MyPat();
    explicit MyPat(int a);
    MyPat(MyPat &pat);
    virtual int eat();
//    int eat();
};


class Dog: public MyPat{
public:
//    virtual int eat();
    int eat();
};

class Cat: public MyPat{
public:
//    virtual int eat();
    int eat();
};

#endif //INC_9_MY_VIRTUAL_PAT_H
