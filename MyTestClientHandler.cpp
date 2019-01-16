#include <cstdlib>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <iostream>
#include <strings.h>
#include "MyTestClientHandler.h"
#include "ISolver.h"
#include "ICacheManager.h"

MyTestClientHandler::MyTestClientHandler() {}

void MyTestClientHandler::handleClient(posix_sockets::TCPClient client) {
    std::string message;
    long msg;
    try {
        while ((msg = client.readLine(message)) > 0 && message != "end") {
            std::cout << message;
        }
        if (msg == 0) {
            std::cout << "Client closed connection" << std::endl;
            client.close();
        }
    } catch (posix_sockets::timeout_exception &e) {
        std::cout << "Client timed out" << std::endl;
        client.close();
    }
}