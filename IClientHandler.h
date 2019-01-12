#ifndef AP_MS2_ICLIENTHANDLER_H
#define AP_MS2_ICLIENTHANDLER_H

namespace server_side {
    class IClientHandler {
    public:
        virtual void handleClient(istream inputStream , ostream outputStream) = 0;
    };
}

#endif //AP_MS2_ICLIENTHANDLER_H
