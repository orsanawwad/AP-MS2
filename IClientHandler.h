#ifndef AP_MS2_ICLIENTHANDLER_H
#define AP_MS2_ICLIENTHANDLER_H

namespace server_side {
    class IClientHandler {
    public:
        virtual void handleClient(int socketIdentity) = 0;
    };
}

#endif //AP_MS2_ICLIENTHANDLER_H
