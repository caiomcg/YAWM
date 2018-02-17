#ifndef YAWM_WAVEDATACHUNCK_H
#define YAWM_WAVEDATACHUNCK_H

#include <cstdint>
#include <iostream>
#include <memory>

#include "Utils.h"

class WaveDataChunck {
private:
    uint32_t sub_chuck_2_id_;
    uint32_t sub_chuck_2_size_;
public:
    explicit WaveDataChunck(uint8_t data[8]) {
        this->sub_chuck_2_id_ = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | (data[3]); // Big Endian
        this->sub_chuck_2_size_ = (data[7] << 24) | (data[6] << 16) | (data[5] << 8) | (data[4]); // Little Endian
    }

    friend std::ostream& operator <<(std::ostream& os, const WaveDataChunck& wave_format_chunck) {
        os << "Wave Format Chuck: " << "\n\n"
            << " - Sub Chuck 2 ID: "   << Utils::byteToString<char>(wave_format_chunck.sub_chuck_2_id_)
            << "\n - Sub Chuck Size: " << wave_format_chunck.sub_chuck_2_size_ << "\n";
        return os;
    }

    uint32_t getSubChunchSize() const {
        return this->sub_chuck_2_size_;
    }
};

#endif // Defines WaveDataChunck.h
