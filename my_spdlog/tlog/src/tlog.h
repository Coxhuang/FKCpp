/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/12/27 6:11 下午
 */

#ifndef MY_SPDLOG_TLOG_H
#define MY_SPDLOG_TLOG_H
#include <iostream>
#include <memory>
#include <mutex>
#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/daily_file_sink.h"

//#define lo TBshellLog::instance()

class TBshellLog{
public:
    TBshellLog();
    ~TBshellLog();
    void hello();

private:
    std::string file_path;
private:
    void init();

private:
    void create_sink();

private:
    std::vector<spdlog::sink_ptr> sinks;
    std::shared_ptr<spdlog::sinks::daily_file_sink_mt> daily_sink;

public:
    std::shared_ptr<spdlog::logger> log_;

public:
    static std::shared_ptr<TBshellLog> instance(); // singleton instance

private:
    static std::shared_ptr<TBshellLog> handle_ptr_;
    static std::mutex cache_handle_mutex_;


};



#endif //MY_SPDLOG_TLOG_H
