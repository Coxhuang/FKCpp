/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/11/8 12:36 下午
 */

#ifndef TOOLS_SINGLETON_TEST_H
#define TOOLS_SINGLETON_TEST_H
#include "../singleton.hpp"

class DerivedSingle:public Singleton<DerivedSingle>{
public:
    DerivedSingle();
    DerivedSingle(token);
    ~DerivedSingle();
    void hello();
    void add_a();
    DerivedSingle(const DerivedSingle&)=delete;
    DerivedSingle& operator =(const DerivedSingle&)= delete;

private:
    int a;
};


#endif //TOOLS_SINGLETON_TEST_H
