//
// Created by Orsan Awwad on 09/01/2019.
//

#ifndef AP_MS2_MYTESTCLIENTHANDLER_H
#define AP_MS2_MYTESTCLIENTHANDLER_H


#include "IClientHandler.h"

class MyTestClientHandler : public server_side::IClientHandler {
public:
    virtual void handleClient(int socketIdentity);
};


#endif //AP_MS2_MYTESTCLIENTHANDLER_H
