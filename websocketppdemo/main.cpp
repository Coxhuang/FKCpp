/*
 * Copyright (c) 2014, Peter Thorson. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the WebSocket++ Project nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL PETER THORSON BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/** ====== WARNING ========
 * This example is presently used as a scratch space. It may or may not be broken
 * at any given time.
 */

#include <websocketpp/config/debug_asio_no_tls.hpp>
#include "include/websocketpp/server.hpp"

// Custom logger
#include <websocketpp/logger/syslog.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/thread.hpp>
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

#include <iostream>
#include <memory>

////////////////////////////////////////////////////////////////////////////////
///////////////// Custom Config for debugging custom policies //////////////////
////////////////////////////////////////////////////////////////////////////////

struct debug_custom : public websocketpp::config::debug_asio {
    typedef debug_custom type;
    typedef debug_asio base;

    typedef base::concurrency_type concurrency_type;

    typedef base::request_type request_type;
    typedef base::response_type response_type;

    typedef base::message_type message_type;
    typedef base::con_msg_manager_type con_msg_manager_type;
    typedef base::endpoint_msg_manager_type endpoint_msg_manager_type;

    /// Custom Logging policies
    /*typedef websocketpp::log::syslog<concurrency_type,
        websocketpp::log::elevel> elog_type;
    typedef websocketpp::log::syslog<concurrency_type,
        websocketpp::log::alevel> alog_type;
    */
    typedef base::alog_type alog_type;
    typedef base::elog_type elog_type;

    typedef base::rng_type rng_type;

    struct transport_config : public base::transport_config {
        typedef type::concurrency_type concurrency_type;
        typedef type::alog_type alog_type;
        typedef type::elog_type elog_type;
        typedef type::request_type request_type;
        typedef type::response_type response_type;
        typedef websocketpp::transport::asio::basic_socket::endpoint
                socket_type;
    };

    typedef websocketpp::transport::asio::endpoint<transport_config>
            transport_type;

    static const long timeout_open_handshake = 0;
};

////////////////////////////////////////////////////////////////////////////////

//typedef websocketpp::server<debug_custom> server;
typedef websocketpp::server<websocketpp::config::asio> server;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

// pull out the type of messages sent by our config
typedef server::message_ptr message_ptr;

bool validate(server *, websocketpp::connection_hdl) {
    //sleep(6);
    return true;
}

void on_http(server* s, websocketpp::connection_hdl hdl) {
    server::connection_ptr con = s->get_con_from_hdl(hdl);
    auto request_method = con->get_request().get_method(); // 请求方式 POST
    auto request_url = con->get_request().get_uri(); // URL
    auto request_data = con->get_request().raw();


    std::stringstream ss;

    con->set_body(ss.str());
    con->set_status(websocketpp::http::status_code::ok);

    std::cout << con->get_response().get_status_code() << std::endl;
}

int main() {
    // Create a server endpoint
    server echo_server;

    try {
        // Set logging settings
        echo_server.set_access_channels(websocketpp::log::alevel::all);
        echo_server.clear_access_channels(websocketpp::log::alevel::frame_payload);

        // Initialize ASIO
        echo_server.init_asio();
        echo_server.set_reuse_addr(true);

        // Register our message handler
        echo_server.set_http_handler(bind(&on_http,&echo_server,::_1));

        echo_server.set_validate_handler(bind(&validate,&echo_server,::_1));

        // Listen on port 9012
        echo_server.listen(9012);
        std::cout << "running: 9012" << std::endl;

        // Start the server accept loop
        echo_server.start_accept();

        // Start the ASIO io_service run loop
        echo_server.run();


    } catch (websocketpp::exception const & e) {
        std::cout << e.what() << std::endl;
    } catch (const std::exception & e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "other exception" << std::endl;
    }
}
