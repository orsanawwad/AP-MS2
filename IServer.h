#ifndef AP_MS2_ISERVER_H
#define AP_MS2_ISERVER_H

#include "IClientHandler.h"

namespace server_side {
    /**
     * Server interface for multi type server implementation.
     */
    class IServer {
    public:
        virtual void open(int port, IClientHandler *clientHandler) = 0;
        virtual void close() = 0;
        virtual ~IServer() {}
    };
}

#endif //AP_MS2_ISERVER_H
