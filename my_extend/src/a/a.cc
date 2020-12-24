/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/12/4 4:50 下午
 */
#include "a.h"

TestA a_obj;
std::shared_ptr<TestA> a_ptr = std::make_shared<TestA>(); // tbs hsm init


TestA::TestA() {
}

void TestA::get_v() {
    std::cout << "ooooo" << std::endl;
}