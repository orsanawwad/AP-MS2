//
// Created by Orsan Awwad on 2019-01-15.
//

#include <sstream>
#include "MyClientHandler.h"
#include "MazeDomain.h"
#include "Searchable.h"

void MyClientHandler::handleClient(posix_sockets::TCPClient client) {
    std::string message;
    std::stringstream data;
    long msg;
    try {
        while ((msg = client.readLine(message)) > 0 && message != "end\n") {
            data << message;
        }
        if (msg == 0) {
            std::cout << "Client closed connection" << std::endl;
        } else {
            std::cout << "Client sent end connection" << std::endl;

            if (cacheManager->doesExist(data.str())) {
                auto solution = cacheManager->get(data.str());
                client.sendMessage(solution);
            } else {
                ISearchable<std::pair<int, int>, double> *searchable = new MazeDomain(data.str());
                auto solution = solver->solve(searchable);
                cacheManager->set(data.str(),solution);
                client.sendMessage(solution);
            }

//            std::cout << wholeMessage.str();
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

MyClientHandler::~MyClientHandler() {}

MyClientHandler::MyClientHandler(server_side::ISolver<ISearchable<std::pair<int, int>, double> *, std::string> *solver,
                                 server_side::ICacheManager<std::string, std::string> *cacheManager) : solver(solver),
                                                                                                       cacheManager(
                                                                                                               cacheManager) {}
