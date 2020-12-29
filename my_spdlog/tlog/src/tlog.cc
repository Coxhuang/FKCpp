/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/12/27 6:11 下午
 */
#include "tlog.h"

std::shared_ptr<TBshellLog> TBshellLog::handle_ptr_ = nullptr; //
std::mutex TBshellLog::cache_handle_mutex_; // static
std::shared_ptr<TBshellLog> TBshellLog::instance() { // static method return singleton instance
    if (TBshellLog::handle_ptr_ == nullptr){
        std::lock_guard<std::mutex> _(cache_handle_mutex_);
        if (TBshellLog::handle_ptr_ == nullptr){
            TBshellLog::handle_ptr_ = std::make_shared<TBshellLog>();
        } else {}
    } else {}
    return TBshellLog::handle_ptr_;
}

TBshellLog::TBshellLog(){
    this->init();
};
TBshellLog::~TBshellLog(){
    spdlog::drop_all();
};


void TBshellLog::hello() {
    std::cout << "hello" << std::endl;
}

void TBshellLog::init() {
    this->file_path = "/Users/cox/Documents/GitHub/FKCpp/my_spdlog/mylog.txt";
    this->create_sink();
    this->log_ = std::make_shared<spdlog::logger>("hahha", begin(sinks), end(sinks));
//    spdlog::register_logger(log_);
    log_->set_pattern("*** [%H:%M:%S %z] [thread %t] %v ***");
}

void TBshellLog::create_sink() {
    this->daily_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>(file_path, 23, 59);
    this->sinks.push_back(this->daily_sink);
}
