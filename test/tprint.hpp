/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/11/12 10:18 上午
 */

#ifndef TOOLS_TPRINT_HPP
#define TOOLS_TPRINT_HPP
#include <iostream>
#include <vector>
#include <map>

namespace trunk{
namespace tools{
namespace tprint{

    template<typename T1, typename T2>
    void print_map(std::map<T1,T2> t_map){ // 打印map
        std::cout << "-size: " << t_map.size() << std::endl;
        for (const auto& iter : t_map){
            std::cout << iter.first << " " << iter.second << std::endl;
        }
    }

    template<typename T>
    void print_vector(std::vector<T> t_vector) { // 打印一维容器
        std::cout << "-size: " << t_vector.size() << std::endl;
        for (const auto& iter : t_vector){
            std::cout << iter << std::endl;
        }
    }

}
}
}

#endif //TOOLS_TPRINT_HPP
