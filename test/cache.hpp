/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/11/12 3:17 下午
 */

#ifndef TEST_CACHE_HPP
#define TEST_CACHE_HPP
#include <iostream>
#include <map>

namespace trunk {
namespace tools {
namespace tcache {
    class TrunkCache{
    public:
        TrunkCache(){
            std::cout << "构造函数" << std::endl;
        };

    public:
        static std::map<std::string, size_t> cache_int;
        static std::map<std::string, std::string> cache_str;
        static int a;
    };

    int TrunkCache::a = 1;

}
}
}


#endif //TEST_CACHE_HPP
