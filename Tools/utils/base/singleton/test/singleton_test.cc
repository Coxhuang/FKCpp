/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/11/8 12:35 下午
 */
#include "singleton_test.h"

DerivedSingle::DerivedSingle() {
    std::cout<<"DerivedSingle"<<std::endl;
}
DerivedSingle::DerivedSingle(token) {
    std::cout<<"destructor called!"<<std::endl;
}

DerivedSingle::~DerivedSingle(){
    std::cout<<"constructor called!"<<std::endl;
}

void DerivedSingle::hello() {
    std::cout<<"Hello"<<std::endl;
}

void DerivedSingle::add_a() {
    a++;
    std::cout << a << std::endl;
}
