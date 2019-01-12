#ifndef AP_MS2_MYTESTCLIENTHANDLER_H
#define AP_MS2_MYTESTCLIENTHANDLER_H


#include "IClientHandler.h"
#include "ISolver.h"
#include "ICacheManager.h"
class MyTestClientHandler : public server_side::IClientHandler {
private:
    Solver <Problem,Solution> *solver;
    CacheManger <Key,Value>*cm;
public:
    MyTestClientHandler(Solver <Problem,Solution> *solver , CacheManger<Key,Value> *cm );

    virtual void handleClient(istream inputStream , ostream outputStream);
};


#endif //AP_MS2_MYTESTCLIENTHANDLER_H
