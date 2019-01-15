//
// Created by Orsan Awwad on 2019-01-15.
//

#include <sstream>
#include "MyClientHandler.h"

void MyClientHandler::handleClient(posix_sockets::TCPClient client) {
    std::string message;
    std::stringstream wholeMessage;
    long msg;
    try {
        while ((msg = client.readLine(message)) > 0 && message != "end\n") {
            wholeMessage << message;
        }
        if (msg == 0) {
            std::cout << "Client closed connection" << std::endl;
        } else {
//            std::cout << wholeMessage.str() << std::endl;
            //TODO: Parse problems
            //TODO: Check for solutions in cache
            //TODO: Run solver on each problem, the solver is an object adapter that should contain 4 instances
            //      of the algorithms and run that problem to each on of them, determine the lowest cost, and retun that.
        }
        client.close();
    } catch (posix_sockets::timeout_exception &e) {
        std::cout << "Client timed out" << std::endl;
        client.close();
    }
}
