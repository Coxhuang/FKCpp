#include <iostream>
#include "src/b/b.h"


struct ST{
    int s = 1;
};

void A(ST& b){

    std::cout<< b.s;
}


int main() {
//    std::cout << "Hello, World!" << std::endl;
//    TestB tb{};
//    tb.get_v();
//    std::shared_ptr<int> a = std::make_shared<int>(1);

//    std::cout<< *a;
//    A(a);

    ST *s_t = new ST;
//    std::cout<< s_t->s;
    A(*s_t);

    return 0;
}
