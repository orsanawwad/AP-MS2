#include "MyParallelServer.h"

#define TIMEOUT_TIME 60

void MyParallelServer::open(int port, server_side::IClientHandler *clientHandler) {
    this->clientHandler = clientHandler;
    this->server = new posix_sockets::TCPServer(port);
    this->server->listen(maxAllowedListens);
    this->serverThread = new std::thread(&MyParallelServer::startAccepting, this);
}

void MyParallelServer::close() {
    threadPool.exit();
}

MyParallelServer::~MyParallelServer() {
    this->serverThread->join();
    delete server;
    this->server = NULL;
    delete this->serverThread;
    this->serverThread = NULL;
}

void MyParallelServer::startAccepting() {
    while (!this->should_exit) {
        try {
            posix_sockets::TCPClient newClient = this->server->accept();
            Task *task = new ClientHandlerTaskAdapter(clientHandler, newClient);
            threadPool.addTask(task);
            this->server->setTimeout(TIMEOUT_TIME);
        } catch (posix_sockets::timeout_exception & e) {
            this->server->close();
            this->close();
            break;
        }
    }
}
