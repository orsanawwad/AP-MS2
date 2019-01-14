#ifndef AP_MS2_MYTESTCLIENTHANDLER_H
#define AP_MS2_MYTESTCLIENTHANDLER_H


#include "IClientHandler.h"
#include "ISolver.h"
#include "ICacheManager.h"

template<typename Problem, typename Solution>
class MyTestClientHandler : public server_side::IClientHandler {
private:
    server_side::ISolver<Problem, Solution> *solver;
    server_side::ICacheManager<Problem, Solution> *cm;
public:
//    MyTestClientHandler(server_side::ISolver <Problem,Solution> *solver, server_side::ICacheManager<Key,Value> *cm );

    MyTestClientHandler(server_side::ISolver<Problem, Solution> *solver,
                        server_side::ICacheManager<Problem, Solution> *cm);

//    virtual void handleClient(int socketIdentify);

    virtual void handleClient(int socketIdentity);

};


#endif //AP_MS2_MYTESTCLIENTHANDLER_H
