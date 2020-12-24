/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/11/26 5:04 下午
 */

#ifndef MASTER_PRT_A_CLASS_HPP
#define MASTER_PRT_A_CLASS_HPP
#include <iostream>


class A{
public:
    A(){
        std::cout << "A 构造函数" << std::endl;
    }

    void set_x(){
        x++;
        std::cout << "x:" << x << std::endl;
    }

    void get_x() const{
        std::cout << "x:" << x << std::endl;
    }

private:
    int x = 1;
};

#endif //MASTER_PRT_A_CLASS_HPP
