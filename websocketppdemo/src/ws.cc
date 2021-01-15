/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/12/21 4:32 下午
 */
#include "ws.h"

namespace trunk {
namespace bshell {
namespace ws {

    std::shared_ptr<BShellWebSocket> BShellWebSocket::ws_ptr_ = nullptr;
    std::mutex BShellWebSocket::ws_mutex_; // static
    std::shared_ptr<BShellWebSocket> BShellWebSocket::instance() {
        if (BShellWebSocket::ws_ptr_ == nullptr){
            std::lock_guard<std::mutex> _(ws_mutex_);
            if (BShellWebSocket::ws_ptr_ == nullptr){
                BShellWebSocket::ws_ptr_ = std::make_shared<BShellWebSocket>();
            } else {}
        } else {}
        return BShellWebSocket::ws_ptr_;
    }

    BShellWebSocket::BShellWebSocket() {
        this->init(); // 初始化 WebSocket
    }

    BShellWebSocket::~BShellWebSocket() {
        tlog->info("~~~~~~~~~~~~~~~~WebSocketpp Destructor~~~~~~~~~~~~~~~~~~~");
    }

    void BShellWebSocket::init() {
        this->init_ptr();
        this->init_ws();
        this->init_member();
    }

    void BShellWebSocket::init_ptr() {
        this->cache_handle_ptr_ = cache::Handle::instance(); // cache handle ptr
    }

    void BShellWebSocket::init_member() {
        this->url_table = {
                std::pair<std::string, unsigned int>("/hello/",0),
                std::pair<std::string, unsigned int>("/api/brainshell/map-start/",1),
                std::pair<std::string, unsigned int>("/api/brainshell/ogm-point/",2),
                std::pair<std::string, unsigned int>("/api/brainshell/emerge-stop/",3),
                std::pair<std::string, unsigned int>("/api/brainshell/login-tos/",4),
                std::pair<std::string, unsigned int>("/api/brainshell/reset-task/",5),
                std::pair<std::string, unsigned int>("/system-msg/",6)
        };
    }

    void BShellWebSocket::init_ws() {
        this->server.set_error_channels(
                websocketpp::log::elevel::all
        ); // log
        this->server.set_access_channels(
                websocketpp::log::alevel::all ^ websocketpp::log::alevel::frame_payload
        );
        this->server.clear_access_channels(
                websocketpp::log::alevel::all
        ); // disable all ws-system log
        this->server.init_asio(); // asio init
        this->server.set_reuse_addr(true); // reset asio listen

        this->server.set_message_handler(std::bind( // set on_message
                &BShellWebSocket::on_message, this,
                std::placeholders::_1, std::placeholders::_2
        ));
        this->server.set_open_handler(std::bind( // set on_open
                &BShellWebSocket::on_open, this, std::placeholders::_1)
        );
        this->server.set_close_handler(std::bind( // set on_close
                &BShellWebSocket::on_close, this, std::placeholders::_1)
        );
        this->server.set_fail_handler(std::bind( // set on_fail
                &BShellWebSocket::on_fail, this, std::placeholders::_1)
        );
        this->server.set_ping_handler(std::bind(
                &BShellWebSocket::on_ping, this, std::placeholders::_1, std::placeholders::_2)
        );
        this->server.set_pong_handler(std::bind(
                &BShellWebSocket::on_pong, this, std::placeholders::_1)
        );
        this->server.set_http_handler(std::bind( // set on_http
                &BShellWebSocket::on_http, this, std::placeholders::_1)
        );
    }

    void BShellWebSocket::run() {
        tlog->info("+++++++++++++ WebSocket running :20200 ++++++++++++++");
        BShellWebSocket::instance()->start();
    }

    void BShellWebSocket::on_open(websocketpp::connection_hdl hdl) {
        tlog->info("-------------- WebSocket open ---------------");
        this->add_user(hdl);
    }

    void BShellWebSocket::on_message(websocketpp::connection_hdl hdl, io_server::message_ptr msg) {
//        tlog->info("-------------- client msg to WebSocket ---------------");
//        for (auto &user : this->user_list) {
//            server.send(user, msg->get_payload(), msg->get_opcode()); // 发送消息 将客户端发来的消息 发回去
//        }
    }

    void BShellWebSocket::on_close(websocketpp::connection_hdl hdl) {
        tlog->info("-------------- WebSocket close ---------------");
        this->del_user(hdl);
    }

    void BShellWebSocket::on_fail(websocketpp::connection_hdl hdl) {
        tlog->info("-------------- WebSocket connect fail ---------------");
    }

    bool BShellWebSocket::on_ping(websocketpp::connection_hdl hdl, std::string s) {
        tlog->info("-------------- WebSocket ping ---------------");
        return true;
    }

    void BShellWebSocket::on_pong(websocketpp::connection_hdl hdl) {
        tlog->info("-------------- WebSocket pong ---------------");
    }

    void BShellWebSocket::on_http(websocketpp::connection_hdl hdl) {
        Json::Value data;
        auto con = this->server.get_con_from_hdl(hdl);
        this->request_before(con);
        this->get_data(data);

        switch (this->route(this->get_url())) {
            case url::map_start: // 获取地图数据
                http::view::HttpView::map_start(con, data);break;
            case url::ogm_point: // 获取静态障碍物
                http::view::HttpView::ogm_point(con, data);break;
            case url::emerge_stop: // 紧急停车
                http::view::HttpView::emerge_stop(con, data);break;
            case url::login_tos: // 登录tos
                http::view::HttpView::login_tos(con, data);break;
            case url::reset_task: // 重置任务
                http::view::HttpView::reset_task(con, data);break;
            case url::system_msg: // 系统信息
                http::view::HttpView::system_msg(con, data);break;
            case url::hello: // 测试
                http::view::HttpView::hello(con, data);break;
            default: // 404
                http::view::HttpView::exception(con);break;
        }; // switch

        this->request_after(con);
    }

    int BShellWebSocket::route(std::string uri) {
        std::map<std::string, unsigned int>::iterator it;
        int target;
        it = this->url_table.find(uri);
        if (it != this->url_table.end()) { // find
            target = (*it).second;
        } else {
            target = 99;
        }
        return target;
    }

    void BShellWebSocket::start() {
        this->server.listen(20200);
        this->server.start_accept();
        this->server.run(); // block
    }

    void BShellWebSocket::server_stop() {
//        if (this->server.is_listening()) {
//            tlog->info("<mouth-websocket> STOP! ");
//            this->server.stop_listening(); // 官方例子关闭server用的是 stop_listening();
//        } else {}
        tlog->info("<mouth-websocket> STOP! ");
        BShellWebSocket::instance()->server.stop_listening();
    }

    void BShellWebSocket::exit() {

    }

    void BShellWebSocket::add_user(websocketpp::connection_hdl hdl) {
        this->user_list.push_back(hdl); // add user
        tlog->info("<mouth-ws> add user,current count:[{}]",this->user_list.size());
    }

    void BShellWebSocket::del_user(websocketpp::connection_hdl hdl) {
        tlog->info("<mouth-ws> delete user");
        std::list<websocketpp::connection_hdl>::iterator users_begin, users_end;
        users_begin = this->user_list.begin();
        users_end = this->user_list.end();
        if (this->user_list.empty()) { ;
        } else if (this->user_list.size() == 1) {
            this->user_list.clear(); // delete user list
        } else { // user count > 1
            for (; users_begin != users_end; users_begin++) {
                io_server::connection_ptr input_con = this->server.get_con_from_hdl(hdl);
                io_server::connection_ptr foo_con = this->server.get_con_from_hdl(*users_begin);
                if (input_con == foo_con) {
                    this->user_list.erase(users_begin);
                    break;
                }
            }
        } // else
        tlog->info("<mouth-ws> delete user,current count:[{}]",this->user_list.size());
    }

    void BShellWebSocket::period_sent() {
        auto subscriber_data = this->cache_handle_ptr_->get_ws(); // subscribe cache data
        std::string response_message = subscriber_data->toStyledString();
        for (auto &user : this->user_list) {
            server.send(user, response_message.c_str(), websocketpp::frame::opcode::TEXT); // 发送Json消息
        }
    }

} // ws
} // bshell
} // trunk


