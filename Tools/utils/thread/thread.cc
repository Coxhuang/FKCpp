/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/11/7 4:53 下午
 */
#include "thread.h"

namespace trunk{
namespace thread{
    TrunkThread::TrunkThread() {
        std::cout << "TrunkThread构造函数" << std::endl;
    }
    TrunkThread::TrunkThread(token) {}
    TrunkThread::~TrunkThread() {}

    int TrunkThread::test_add_a() {  // 测试 成员
        test_a++;
        std::cout << test_a << std::endl;
        return test_a;
    }
}
}
 