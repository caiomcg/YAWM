#ifndef YAWM_UTILS_H
#define YAWM_UTILS_H

#include <memory>
#include <sstream>

namespace Utils {
    template<typename T>
    std::string byteToString(auto data) {
        std::stringstream ss;
        for (int i = (sizeof(data) - 1); i >= 0; i--) {
            ss << (T)((data >> 8*i) & 0xFF);
        }
        return ss.str();
    }

}

#endif // Defines Utils.h
