#include <iostream>
#include "src/ws.h"
#include <thread>



int main() {

//    trunk::bshell::ws::BShellWebSocket ws;
//    ws.hi();
//    ws.start();

    std::thread t_ws(&trunk::bshell::ws::BShellWebSocket::run);
    t_ws.join();

}
