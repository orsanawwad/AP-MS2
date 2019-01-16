#ifndef AP_MS2_MYTESTCLIENTHANDLER_H
#define AP_MS2_MYTESTCLIENTHANDLER_H


#include "IClientHandler.h"
#include "ISolver.h"
#include "ICacheManager.h"


class MyTestClientHandler : public server_side::IClientHandler {
private:

public:

    MyTestClientHandler();

    virtual void handleClient(posix_sockets::TCPClient client);

};


#endif //AP_MS2_MYTESTCLIENTHANDLER_H
