/*
 * Copyright (C) Trunk Technology, Inc. - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Huang Minhang <huangminhang@trunk.tech>, 2020/12/21 4:32 下午
 */

#ifndef TBRAIN_WS_H
#define TBRAIN_WS_H
#include <json/json.h>
#include <iostream>
#include <functional>
#include <mutex>
#include <memory>
#include <map>
#include <list>
#include <websocketpp/config/debug_asio_no_tls.hpp>
#include "../include/websocketpp/server.hpp"
#include <websocketpp/config/asio_no_tls.hpp>
#include <iostream>
#include <memory>


namespace trunk {
namespace bshell {
namespace ws {

    typedef websocketpp::server<websocketpp::config::asio> io_server;

class BShellWebSocket {

    public:
        BShellWebSocket();
        ~BShellWebSocket();

    public:
        void hi();

    public:
        void init();
        void start();
        static void run();

    private:
        void init_ws();

    public:
        void on_open(const websocketpp::connection_hdl& hdl); // open callback
        void on_message(const websocketpp::connection_hdl& hdl, const io_server::message_ptr& msg); // message callback
        void on_close(const websocketpp::connection_hdl& hdl); // close callback
        void on_fail(const websocketpp::connection_hdl& hdl); // conn fail callback
        bool on_ping(const websocketpp::connection_hdl& hdl, const std::string& s); // ping callback
        void on_pong(const websocketpp::connection_hdl& hdl); // pong callback
        void on_http(websocketpp::connection_hdl hdl); // http
    public:
        void add_user(const websocketpp::connection_hdl& hdl);
        void del_user(const websocketpp::connection_hdl& hdl);
    public:
        int route(const std::string&);
    public:
        std::map<std::string, unsigned int> url_table;
        enum url {hello=0, map_start=1, ogm_point=2, emerge_stop=3, login_tos=4, reset_task=5, system_msg=6};
    private:
        io_server server;
        unsigned int ws_port{};
        std::list <websocketpp::connection_hdl> user_list; // 用户列表

    };

}
}
}



#endif //TBRAIN_WS_H
