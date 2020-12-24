#include <iostream>
#include "a_class.hpp"
#include "b_class.hpp"


int main() {
//    A a;
    std::shared_ptr<A> make_a = std::make_shared<A>();
//    std::cout << &a << std::endl;
//    std::cout << &make_a << std::endl;

    make_a->get_x();
    make_a->set_x();
    make_a->get_x();
    B b(make_a);
    b.b_get_x();



    return 0;
}
