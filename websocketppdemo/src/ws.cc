/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/12/21 4:32 下午
 */
#include "ws.h"

#include <utility>

namespace trunk {
namespace bshell {
namespace ws {

    BShellWebSocket::BShellWebSocket() {
        this->init(); // 初始化 WebSocket
    }

    void BShellWebSocket::hi() {
        std::cout << "hello" << std::endl;
    }

    BShellWebSocket::~BShellWebSocket() {
    }

    void BShellWebSocket::init() {
        this->init_ws();
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

    void BShellWebSocket::on_open(const websocketpp::connection_hdl& hdl) {
        this->add_user(hdl);
    }

    void BShellWebSocket::on_message(const websocketpp::connection_hdl& hdl, const io_server::message_ptr& msg) {
        for (auto &user : this->user_list) {
            server.send(user, msg->get_payload(), msg->get_opcode()); // 发送消息 将客户端发来的消息 发回去
        }
    }

    void BShellWebSocket::on_close(const websocketpp::connection_hdl& hdl) {
        this->del_user(hdl);
    }

    void BShellWebSocket::on_fail(const websocketpp::connection_hdl& hdl) {
    }

    bool BShellWebSocket::on_ping(const websocketpp::connection_hdl& hdl, const std::string& s) {
        return true;
    }

    void BShellWebSocket::on_pong(const websocketpp::connection_hdl& hdl) {
    }

    void BShellWebSocket::on_http(websocketpp::connection_hdl hdl) {
//        auto con = this->server.get_con_from_hdl(std::move(hdl));
        auto con = this->server.get_con_from_hdl(std::move(hdl));

        std::stringstream ss;
        ss << "got HTTP request with " << " bytes of body data.";

        con->set_body(ss.str());
        con->set_status(websocketpp::http::status_code::ok);
    }

    int BShellWebSocket::route(const std::string& uri) {
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

    void BShellWebSocket::run() {
        BShellWebSocket ws;
        ws.start();
    }

    void BShellWebSocket::start() {
        this->server.listen(20200);
        this->server.start_accept();
        this->server.run(); // block
    }

    void BShellWebSocket::add_user(const websocketpp::connection_hdl& hdl) {
        this->user_list.push_back(hdl); // add user
    }

    void BShellWebSocket::del_user(const websocketpp::connection_hdl& hdl) {
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
    }

} // ws
} // bshell
} // trunk


