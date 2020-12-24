#include <iostream>
#include <vector>
#include <functional>
#include <list>
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
//#include <websocketpp/config/asio_no_tls_client.hpp>
//#include <websocketpp/client.hpp>



typedef websocketpp::server<websocketpp::config::asio> io_server;


class WebSocketServer {

public:
    WebSocketServer() {
//        m_listClientConnection.clear(); // 清空用户池
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

    void on_open(websocketpp::connection_hdl hdl) {
        std::cout << "on_open" << std::endl;
//        server.get_connection();
        this->add_user(hdl);
    }

    void on_message(websocketpp::connection_hdl hdl, io_server::message_ptr msg) {
        std::cout << "on_message" << std::endl;
//        server.send(hdl, msg->get_payload(), msg->get_opcode()); // 发送消息
        for (auto &i : m_listClientConnection){
            server.send(i, msg->get_payload(), msg->get_opcode()); // 发送消息
        }
    }

    void on_close(websocketpp::connection_hdl hdl) {
        std::cout << "on_close" << std::endl;
        this->del_user(hdl);
    }

    void on_fail(websocketpp::connection_hdl hdl) {
        std::cout << "on_fail" << std::endl;
    }

    void add_user(websocketpp::connection_hdl hdl){
        m_listClientConnection.push_back(hdl);
    }

    void del_user(websocketpp::connection_hdl hdl){
        std::list<websocketpp::connection_hdl>::iterator iter, iterEnd;
        iter = m_listClientConnection.begin();
        iterEnd = m_listClientConnection.end();
        if (m_listClientConnection.empty()){
            std::cout << "-------------------空" << std::endl;
            ;
        } else if (m_listClientConnection.size() == 1){
            std::cout << "-------------------1" << std::endl;
            m_listClientConnection.erase(iter);
        } else{
            std::cout << "-------------------多:" << m_listClientConnection.size() << std::endl;

            for (iter; iter != iterEnd; iter++)
            {
                io_server::connection_ptr conInput = server.get_con_from_hdl(hdl);
                io_server::connection_ptr conSrc = server.get_con_from_hdl(*iter);
                if (conInput == conSrc)
                {
                    m_listClientConnection.erase(iter);
                    break;
                }
            }
        }

    }


    void run() {
        server.listen(8888); // 端口 9002
        server.start_accept();
        server.run();
    }

public:
    io_server server;
    std::list<websocketpp::connection_hdl> m_listClientConnection;
};

int main() {
    WebSocketServer app;
    app.run();
    return 0;
}
