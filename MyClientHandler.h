//
// Created by Orsan Awwad on 2019-01-15.
//

#ifndef AP_MS2_MYCLIENTHANDLER_H
#define AP_MS2_MYCLIENTHANDLER_H


#include "IClientHandler.h"
#include "ISolver.h"
#include "ICacheManager.h"

class MyClientHandler : public server_side::IClientHandler{
//    server_side::ISolver<>* solver;
//    server_side::ICacheManager<>* cacheManager;
public:
    virtual void handleClient(posix_sockets::TCPClient client);
};


#endif //AP_MS2_MYCLIENTHANDLER_H
