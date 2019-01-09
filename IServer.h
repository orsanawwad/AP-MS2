//
// Created by Orsan Awwad on 08/01/2019.
//

#ifndef AP_MS2_ISERVER_H
#define AP_MS2_ISERVER_H

#include "IClientHandler.h"

namespace server_side {
    class IServer {
    public:
        virtual void open(int port, IClientHandler *clientHandler) = 0;
        virtual void close() = 0;
    };
}

#endif //AP_MS2_ISERVER_H
