#ifndef AP_MS2_MYTESTCLIENTHANDLER_H
#define AP_MS2_MYTESTCLIENTHANDLER_H


#include "IClientHandler.h"
#include "ISolver.h"
#include "ICacheManager.h"
class MyTestClientHandler : public server_side::IClientHandler {
private:
    Solver solver;
    CacheManger cm;
public:
    MyTestClientHandler();
    virtual void handleClient(int socketIdentity);
};


#endif //AP_MS2_MYTESTCLIENTHANDLER_H
