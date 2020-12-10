#include <iostream>
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>
#include <functional>

typedef websocketpp::server<websocketpp::config::asio> io_server;
typedef websocketpp::client<websocketpp::config::asio_client> io_client;



class WebSocketServer {

public:
    WebSocketServer() {
        server.set_error_channels(websocketpp::log::elevel::all); // log
        server.set_access_channels(websocketpp::log::alevel::all ^ websocketpp::log::alevel::frame_payload);
        server.init_asio(); // asio init
        server.set_message_handler(std::bind( // set on_message
                &WebSocketServer::on_message, this,
                std::placeholders::_1, std::placeholders::_2
        ));
        server.set_open_handler(std::bind( // set on_open
                &WebSocketServer::on_open, this, std::placeholders::_1)
        );
        server.set_close_handler(std::bind( // set on_close
                &WebSocketServer::on_close, this, std::placeholders::_1)
        );
        server.set_fail_handler(std::bind( // set on_fail
                &WebSocketServer::on_fail, this, std::placeholders::_1)
        );

    }

    void on_message(websocketpp::connection_hdl hdl, io_server::message_ptr msg) {
        std::cout << "on_message" << std::endl;
        server.send(hdl, msg->get_payload(), msg->get_opcode()); // 发送消息
    }

    void on_open(websocketpp::connection_hdl hdl) {
        std::cout << "on_open" << std::endl;
    }

    void on_close(websocketpp::connection_hdl hdl) {
        std::cout << "on_close" << std::endl;
    }

    void on_fail(websocketpp::connection_hdl hdl) {
        std::cout << "on_fail" << std::endl;
    }


    void run() {
        server.listen(8888); // 端口 9002
        server.start_accept();
        server.run();
    }

public:
    io_server server;
    io_client client;
};

int main() {
    WebSocketServer app;
    app.run();
    return 0;
}
