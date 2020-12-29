#include <climits>
/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/12/28 11:43 上午
 */

#ifndef MY_SPDLOG_LOG_HPP
#define MY_SPDLOG_LOG_HPP
#include <iostream>
#include <memory>
#include <mutex>
#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/daily_file_sink.h"


class TLogger{

public:
    static TLogger& instance() {
        static TLogger m_instance;
        return m_instance;
    }

    auto get_logger() const{
        return this->logger_;
    }

private:
    TLogger() {
        this->init();
    }

    ~TLogger() {
        spdlog::drop_all();
    }

private:
    void init(){
        this->init_file(); // 后继: init_logger
        this->init_logger(); // 前驱: init_file
    }

    void init_file(){
        this->log_root_path = "/var/log/trunk/brainshell";
        this->info_file_path = "bshell_info.log";
        this->error_file_path = "bshell_erro.log";
        this->rotation_h = 5;
        this->rotation_m = 59;
    }

    void init_logger(){

        this->info_sink_ = std::make_shared<spdlog::sinks::daily_file_sink_mt>(this->log_root_path+ this->info_file_path,this->rotation_h,this->rotation_m);
        this->error_sink_ = std::make_shared<spdlog::sinks::daily_file_sink_mt>(this->log_root_path+ this->error_file_path,this->rotation_h,this->rotation_m);
        this->console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        this->info_sink_->set_level(spdlog::level::debug); // debug < info< warning< error< critical  日志信息低于设置的级别时, 不予显示
        this->error_sink_->set_level(spdlog::level::err);
        this->console_sink->set_level(spdlog::level::debug);
        this->sinks_.push_back(this->info_sink_);
        this->sinks_.push_back(this->error_sink_);
        this->sinks_.push_back(this->console_sink);
        this->logger_ = std::make_shared<spdlog::logger>("bshell", begin(this->sinks_), end(this->sinks_));
        this->logger_->set_pattern("[%l] [%Y:%m:%d %H:%M:%S,%e] [Process-%P] %v");
        this->logger_->flush_on(spdlog::level::info); // 设置当触发 info 或更严重的错误时立刻刷新日志到 disk
        spdlog::register_logger(this->logger_); // 注册logger
        spdlog::flush_every(std::chrono::seconds(5)); // 每隔一秒刷新一次日志
    }

private:
    std::shared_ptr<spdlog::logger> logger_;
    std::shared_ptr<spdlog::sinks::daily_file_sink_mt> info_sink_;
    std::shared_ptr<spdlog::sinks::daily_file_sink_mt> error_sink_;
    std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> console_sink;
    std::vector<spdlog::sink_ptr> sinks_;
    std::string log_root_path;
    std::string error_file_path;
    std::string info_file_path;
    short int rotation_h;
    short int rotation_m;

}; // TLogger


#define log TLogger::instance().get_logger()


////#define LDebug(...) TLogger::instance().GetLogger()->debug(__VA_ARGS__)
//#define LInfo(...) TLogger::instance().get_logger()->info(__VA_ARGS__)
//#define LWarn(...) TLogger::instance().get_logger()->warn(__VA_ARGS__)
//#define log TLogger::instance().get_logger()
////#define LInfo(...) TLogger::instance()->logger_->info(__VA_ARGS__)
////#define LWarn(...) TLogger::instance().GetLogger()->warn(__VA_ARGS__)
////#define LError(...) TLogger::instance().GetLogger()->error(__VA_ARGS__)
////#define LCritical(...) TLogger::instance().GetLogger()->critical(__VA_ARGS__)


#endif //MY_SPDLOG_LOG_HPP
