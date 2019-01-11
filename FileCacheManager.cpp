#include "FileCacheManager.h"

bool FileCacheManager::doesExist(std::string key) {
    return solutionsMap.count(key);
}

std::string FileCacheManager::get(std::string key) {
    if (doesExist(key)) {
        return solutionsMap[key];
    } else {
        return null;
    }
}

void FileCacheManager::set(std::string key, std::string value) {

    solutionsMap[key] = value;
}
