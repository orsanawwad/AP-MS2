#ifndef AP_MS2_MYSERIALSERVER_H
#define AP_MS2_MYSERIALSERVER_H


#include "IServer.h"

class MySerialServer : public server_side::IServer {
public:
    virtual void open(int port, server_side::IClientHandler * clientHandler);

    virtual void close();
};


#endif //AP_MS2_MYSERIALSERVER_H
