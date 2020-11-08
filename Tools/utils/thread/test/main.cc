/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/11/7 5:03 下午
 */
#include <iostream>
#include "thread.h"



int main() {
    std::cout << "Hello, Thread!" << std::endl;

    trunk::thread::TrunkThread thread_instance;

    std::cout << trunk::thread::a;

    return 0;
}
