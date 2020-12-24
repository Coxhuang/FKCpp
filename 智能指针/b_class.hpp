/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/11/26 5:05 下午
 */

#ifndef MASTER_PRT_B_CLASS_HPP
#define MASTER_PRT_B_CLASS_HPP

#include <iostream>
#include "a_class.hpp"

class B{
public:
    B(){
        std::cout << "B 构造函数" << std::endl;
    }
    explicit B(std::shared_ptr<A>& a) {
        a_ptr = a;
        std::cout << "B 参数" << std::endl;
    }

    void b_get_x() const {
        a_ptr->get_x();
    }

private:
    std::shared_ptr<A> a_ptr;
};

#endif //MASTER_PRT_B_CLASS_HPP
