//
// Created by Cox on 2020/9/10.
//
#include "iostream"

using namespace std;



class Animal{
public:
    void get_a(){
        std::cout << "Base a\n";
    };
    virtual void get_b(){
        std::cout << "Base b\n";
    };

}animal;

class Dog: public Animal{
public:
    void get_a(){
        std::cout << "Dog a\n";
    };
    void get_b(){
        std::cout << "Dog b\n";
    };
}dog;



int main()
{
//    animal.get_a(); // Base a
//    animal.get_b(); // Base b
//    dog.get_a(); // Dog a
//    dog.get_b(); // Dog b

//    Animal *p;
//    p = &dog;
//    p->get_a(); // Base a
//    p->get_b(); // Dog b

//    Animal *p;
//    p = &animal;
//    p->get_a(); // Base a
//    p->get_b(); // Base b


    return 0;
}
