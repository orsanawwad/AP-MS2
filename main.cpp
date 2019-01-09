#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"

int main() {
//    std::cout << "Hello, World!" << std::endl;

    server_side::IServer * server = new MySerialServer;
    server_side::IClientHandler * clientHandler = new MyTestClientHandler;

    server->open(1000,clientHandler);

    return 0;
}