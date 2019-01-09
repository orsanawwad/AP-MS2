//
// Created by Orsan Awwad on 08/01/2019.
//

#ifndef AP_MS2_ICACHEMANAGER_H
#define AP_MS2_ICACHEMANAGER_H

namespace server_side {
    template <typename Key, typename Value>
    class ICacheManager {
    public:
        virtual bool doesExist(Key key) = 0;
        virtual Value get(Key key) = 0;
        virtual bool set(Key key) = 0;
    };
}

#endif //AP_MS2_ICACHEMANAGER_H
