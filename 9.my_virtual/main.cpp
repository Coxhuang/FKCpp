#include <iostream>
#include "home/pat.h"

using namespace std;

int main() {
    /*
    1. 堆上实例化
    */

    MyPat *pat1_1 = new MyPat; // 实例化一个 基类MyPat指针指向MyPat的对象
    pat1_1->eat(); // 基类 eat()
    delete pat1_1;

    MyPat *pat1_2 = new Dog; // 实例化一个 基类MyPat指针指向Dog的对象
    pat1_2->eat(); // 基类 eat()
    delete pat1_2;

//    MyPat *pat1_3 = new Cat; // 实例化一个 基类MyPat指针指向Cat的对象
//    pat1_3->eat(); // 基类 eat()
//    delete pat1_3;
//
//    Dog *pat1_4 = new Dog; // 实例化一个 基类MyPat指针指向Dog的对象
//    pat1_4->eat(); // Dog类 eat()
//    delete pat1_4;
//
//    Cat *pat1_5 = new Cat; // 实例化一个 基类MyPat指针指向Cat的对象
//    pat1_5->eat(); // Cat类 eat()
//    delete pat1_5;

    /*
    堆上实例化
        a.
    */



    /*
    2. 栈上实例化
    */
    return 0;
}
