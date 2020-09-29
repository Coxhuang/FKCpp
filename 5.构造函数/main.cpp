#include <iostream>
#include "home/pat.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    MyPat pat1;
    MyPat pat2(10);
    MyPat pat3('q');
    MyPat pat4("22");
    return 0;
}
