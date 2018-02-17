#ifndef YAWM_WAVE_H
#define YAWM_WAVE_H

#include "WaveHeader.h"
#include "WaveFormatChunk.h"

#include <iostream>
#include <fstream>
#include <memory>

class Wave {
public:
    Wave(const std::string& path, const uint32_t byteInterval=512);

private:
    bool openFile(const std::string& path);
    std::shared_ptr<uint8_t> getBytes(uint32_t bytes);

    std::fstream file_;
    std::unique_ptr<WaveHeader> header_;
};

#endif // Defines Wave.h
