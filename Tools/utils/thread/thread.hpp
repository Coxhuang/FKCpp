/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/11/8 10:50 下午
 */

#ifndef TOOLS_THREAD_HPP
#define TOOLS_THREAD_HPP

#include <iostream>
#include "../base/singleton/singleton.hpp"

namespace trunk{
namespace thread{

class TrunkThread : public Singleton<TrunkThread>{
public:
//    TrunkThread(){
//        std::cout << "TrunkThread构造函数" << std::endl;
//    };
    TrunkThread(token){
        std::cout << "TrunkThread token 构造函数" << std::endl;
    };
    ~TrunkThread(){};
    TrunkThread(const TrunkThread&)=delete;
    TrunkThread& operator =(const TrunkThread&)= delete;

public: // 测试 成员
    int test_add_a(){
        test_a++;
        std::cout << test_a << std::endl;
        return test_a;
    };
    int test_a;
};


}
}

#endif //TOOLS_THREAD_HPP
