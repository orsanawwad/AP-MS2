#ifndef AP_MS2_FILECACHEMANAGER_H
#define AP_MS2_FILECACHEMANAGER_H

#define DEFAULT_CACHE "default.txt"

#include <string>
#include <map>
#include "ICacheManager.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <mutex>
#include "Base64Codec.h"

using namespace std;

/**
 * File cache manager implementation.
 */
class FileCacheManager : public server_side::ICacheManager<std::string, std::string> {
    std::mutex cache_mutex;
public:
    FileCacheManager();

    FileCacheManager(std::string fileName);

    virtual std::unordered_map<std::string, std::string> loadFromFile();

    virtual void saveToFile(unordered_map<string, string> problemSoultion);

    std::vector<std::string> parseCSVLine(std::string line);

    /**
     * Check if cache exists from key.
     * @param key the key to check.
     * @return
     */
    virtual bool doesExist(std::string key);

    /**
     * Get cache of key.
     * @param key object to get.
     * @return cache type.
     */
    virtual std::string get(std::string key);

    /**
     * Set or update cache of key.
     * @param key object to update.
     * @param value value to update.
     */
    virtual void set(std::string key, std::string value);

    virtual string getFileName() {
        return this->fileName;
    }

private:

    server_side::Base64Codec base64Codec;

    std::string fileName;

public:
    virtual ~FileCacheManager();

};


#endif //AP_MS2_FILECACHEMANAGER_H
