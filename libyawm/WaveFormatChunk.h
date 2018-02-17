#ifndef YAWM_WAVEFORMATCHUNK_h
#define YAWM_WAVEFORMATCHUNK_h

#include <cstdint>
#include <iostream>

#include "Utils.h"

class WaveFormatChunk {
private:
    uint32_t sub_chuck_id_;
    uint32_t sub_chunck_size_;
    uint16_t audio_format_;
    uint16_t channels_;
    uint32_t sample_rate_;
    uint32_t byte_rate_;    
    uint16_t block_align_;
    uint16_t bits_per_sample;
public:
    explicit WaveFormatChunk(uint8_t data[24]) : sub_chuck_id_{0}, sub_chunck_size_{0}, audio_format_{0}, channels_{0}, sample_rate_{0}, byte_rate_{0}, block_align_{0}, bits_per_sample{0} {
        this->sub_chuck_id_     = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | (data[3]); // Big Endian
        this->sub_chunck_size_  = (data[7] << 24) | (data[6] << 16) | (data[5] << 8) | (data[4]); // Little Endian
        this->audio_format_     = (data[9] << 8) | (data[8]); // Little Endian
        this->channels_         = (data[11] << 8) | (data[10]); // Little Endian
        this->sample_rate_      = (data[15] << 24) | (data[14] << 16) | (data[13] << 8) | (data[12]); // Little Endian
        this->byte_rate_        = (data[19] << 24) | (data[18] << 16) | (data[17] << 8) | (data[16]); // Little Endian
        this->block_align_      = (data[21] << 8) | (data[20]); // Little Endian
        this->bits_per_sample   = (data[23] << 8) | (data[22]); // Little Endian
    }

    friend std::ostream& operator <<(std::ostream& os, const WaveFormatChunk& wave_format_chunck) {
        os << "Wave Format Chuck: " << "\n\n"
            << " - Sub Chuck ID: "   << Utils::byteToString<char>(wave_format_chunck.sub_chuck_id_)
            << "\n - Sub Chuck Size: " << wave_format_chunck.sub_chunck_size_
            << "\n - Audio Format: " << wave_format_chunck.audio_format_
            << "\n - Channels: " << wave_format_chunck.channels_
            << "\n - Sample Rate: " << wave_format_chunck.sample_rate_
            << "\n - Byte Rate: " << wave_format_chunck.byte_rate_
            << "\n - Block Align: " << wave_format_chunck.block_align_
            << "\n - Bits Per Sample: " << wave_format_chunck.bits_per_sample << "\n";
        return os;
    }

    uint32_t getSampleRate() const {
        return this->sample_rate_;
    }

    uint16_t getChannels() const {
        return this->channels_;
    }

    uint16_t getBitsPerSample() const {
        return this->bits_per_sample;
    }

    uint16_t getBlockAlign() const {
        return this->block_align_;
    }
};

#endif // Defines WaveFormatChunk.h
