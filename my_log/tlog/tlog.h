/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/12/23 2:24 下午
 */

#ifndef MY_LOG_TLOG_H
#define MY_LOG_TLOG_H
#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/rotating_file_sink.h"

class Tlog{
public:
    Tlog();
    ~Tlog();

public:
    void hello();

public:



};

#endif //MY_LOG_TLOG_H
