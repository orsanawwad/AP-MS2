#ifndef AP_MS2_FILECACHEMANAGER_H
#define AP_MS2_FILECACHEMANAGER_H

#include <string>
#include "ICacheManager.h"

class FileCacheManager : server_side::ICacheManager<std::string, std::string> {
    virtual bool doesExist(std::string key);

    virtual std::string get(std::string key);

    virtual void set(std::string key,std::string value);
};


#endif //AP_MS2_FILECACHEMANAGER_H
