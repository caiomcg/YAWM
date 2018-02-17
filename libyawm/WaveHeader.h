#ifndef YAWM_WAVEHEADER_H
#define YAWM_WAVEHEADER_H

#include <cstdint>
#include <iostream>
#include <memory>

#include "Utils.h"
#include "WaveFormatChunk.h"
#include "WaveDataChunck.h"

class WaveHeader {
public:
    explicit WaveHeader(uint8_t data[44]) : chunck_id_{0}, chunck_size_{0}, format_{0} {
        this->chunck_id_ = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | (data[3]); // Big Endian
        this->chunck_size_ = (data[7] << 24) | (data[6] << 16) | (data[5] << 8) | (data[4]); // Little Endian
        this->format_ = (data[8] << 24) | (data[9] << 16) | (data[10] << 8) | (data[11]); // Big Endian

        this->format_chunck_ = std::make_unique<WaveFormatChunk>(data + 12);
        std::clog << *this->format_chunck_ << std::endl;

        this->data_chunck_ = std::make_unique<WaveDataChunck>(data + 36);
        std::clog << *this->data_chunck_ << std::endl;
    }

    bool isWave() const {

    }

    double getDuration() const {
        return (double)this->data_chunck_->getSubChunchSize() / (double)(this->format_chunck_->getSampleRate() * this->format_chunck_->getChannels() *
        this->format_chunck_->getBitsPerSample() / 8.0);
    }

    friend std::ostream& operator <<(std::ostream& os, const WaveHeader& wave_header) {
         os << "Wave Header: " << "\n\n"
            << " - Chuck ID: "   << Utils::byteToString<char>(wave_header.chunck_id_)
            << "\n - Chuck Size: " << wave_header.chunck_size_
            << "\n - Format: "   << Utils::byteToString<char>(wave_header.format_)
            << "\n";
        return os;
    }
private:
    uint32_t chunck_id_;
    uint32_t chunck_size_;
    uint32_t format_;
    std::unique_ptr<WaveFormatChunk> format_chunck_;
    std::unique_ptr<WaveDataChunck>  data_chunck_;
};

#endif // Defines WaveHeader.h
