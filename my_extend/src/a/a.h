/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/12/4 4:50 下午
 */

#ifndef MY_EXTEND_A_H
#define MY_EXTEND_A_H
#include <iostream>
#include <memory>


class TestA{
public:
    TestA();
    int v_a;
    int v_b;
    int v_c;
//    std::shared_ptr<TestA> a_ptr;

public:
    void get_v();
};

#endif //MY_EXTEND_A_H
