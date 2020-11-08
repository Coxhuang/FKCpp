/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/11/7 5:03 下午
 */
#include <iostream>
#include "../thread.h"



int main() {

    trunk::thread::TrunkThread& instance1 = trunk::thread::TrunkThread::get_instance();
    trunk::thread::TrunkThread& instance2 = trunk::thread::TrunkThread::get_instance();
    instance1.test_add_a(); // output: 1
    instance2.test_add_a(); // output: 2

    return 0;
}
