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
#include "../../app_nerve/base/cache.h"
#include "http/base.h"
#include "http/view.h"


namespace trunk {
namespace bshell {
namespace ws {

    typedef websocketpp::server<websocketpp::config::asio> io_server;

class BShellWebSocket: public http::BShellWebSocketHttpBase {

    public:
        BShellWebSocket();
        ~BShellWebSocket();

    public:
        static void run();

    public:
        static void server_stop();

    public:
        void init();
        void start();
        void exit();

    private:
        void init_ptr();
        void init_ws();
        void init_member();

    public:
        void on_open(websocketpp::connection_hdl hdl); // open callback
        void on_message(websocketpp::connection_hdl hdl, io_server::message_ptr msg); // message callback
        void on_close(websocketpp::connection_hdl hdl); // close callback
        void on_fail(websocketpp::connection_hdl hdl); // conn fail callback
        bool on_ping(websocketpp::connection_hdl hdl, std::string s); // ping callback
        void on_pong(websocketpp::connection_hdl hdl); // pong callback
        void on_http(websocketpp::connection_hdl hdl); // http
    public:
        void add_user(websocketpp::connection_hdl hdl);
        void del_user(websocketpp::connection_hdl hdl);
    public:
        void period_sent();
    public:
        int route(std::string);
    public:
        std::map<std::string, unsigned int> url_table;
        enum url {hello=0, map_start=1, ogm_point=2, emerge_stop=3, login_tos=4, reset_task=5, system_msg=6};
    private:
        io_server server;
        unsigned int ws_port;
        std::list <websocketpp::connection_hdl> user_list; // 用户列表
    public:
        static std::shared_ptr<BShellWebSocket> instance(); // singleton instance
    public:
        static std::mutex ws_mutex_;
        static std::shared_ptr<BShellWebSocket> ws_ptr_;
        std::shared_ptr<cache::Handle> cache_handle_ptr_;

    };

}
}
}



#endif //TBRAIN_WS_H
