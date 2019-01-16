#ifndef AP_MS2_BASE64CODEC_H
#define AP_MS2_BASE64CODEC_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <string>
#include <vector>

namespace server_side {
    /**
     * Base 64 implementation used to easily decode and encode strings, used mainly for cache saving to save headache
     * of splitting the lines.
     */
    class Base64Codec {
    private:
        const std::string base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

        bool isBase64(unsigned char c);

    public:
        /**
         * Encode value.
         * @return base64 encoded string.
         */
        std::string encodeValue(const std::string &value);

        /**
         * Decoded value.
         * @return base64 decoded string.
         */
        std::string decodeValue(const std::string &value);
    };
}

#endif //AP_MS2_BASE64CODEC_H
