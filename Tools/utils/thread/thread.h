/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/11/7 4:53 下午
 */

#ifndef TOOLS_THREAD_H
#define TOOLS_THREAD_H
#include <iostream>
#include "../base/singleton/singleton.hpp"

namespace trunk{
namespace thread{

class TrunkThread : public Singleton<TrunkThread>{
public:
    TrunkThread();
    TrunkThread(token);
    ~TrunkThread();
    TrunkThread(const TrunkThread&)=delete;
    TrunkThread& operator =(const TrunkThread&)= delete;

public: // 测试 成员
    int test_add_a();
    int test_a;
};


}
}

#endif //TOOLS_THREAD_H
