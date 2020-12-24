/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/12/4 4:50 下午
 */
#include "b.h"


//extern TestA a_obj;
extern std::shared_ptr<TestA> a_ptr;

void TestB::get_v() {
    std::cout << "xxxxxx" << std::endl;
//    a_obj.get_v();
    a_ptr->get_v();
}