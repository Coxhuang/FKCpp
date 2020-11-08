/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/11/8 12:31 下午
 */
#include <iostream>
#include "singleton_test.h"


int main() {
    std::cout << "Hello, Singleton Base!" << std::endl;
    DerivedSingle& instance1 = DerivedSingle::get_instance();
    DerivedSingle& instance2 = DerivedSingle::get_instance();
    instance1.add_a(); // a++ 打印a
    instance2.add_a(); // a++ 打印a
    return 0;
}

