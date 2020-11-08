/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/11/7 5:59 下午
 */

#ifndef TOOLS_SINGLETON_HPP
#define TOOLS_SINGLETON_HPP

// brief: a singleton base class offering an easy way to create singleton
/*
class DerivedSingle:public Singleton<DerivedSingle>{
public:
    DerivedSingle();
    DerivedSingle(token);
    ~DerivedSingle();
    DerivedSingle(const DerivedSingle&)=delete;
    DerivedSingle& operator =(const DerivedSingle&)= delete;
};
DerivedSingle& instance1 = DerivedSingle::get_instance(); // 必须是类的引用
DerivedSingle& instance2 = DerivedSingle::get_instance(); // 必须是类的引用
// instance1和instance2是同一个实例
 */
#include <iostream>

template<typename T>
class Singleton {
public:
    static T &get_instance() noexcept(std::is_nothrow_constructible<T>::value) {
        static T instance{token()};
        return instance;
    }

    virtual ~Singleton() = default;

    Singleton(const Singleton &) = delete;

    Singleton &operator=(const Singleton &) = delete;

protected:
    struct token {
    }; // helper class
    Singleton() noexcept = default;
};

#endif //TOOLS_SINGLETON_HPP
