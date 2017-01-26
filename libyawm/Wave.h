#ifndef YAWM_WAVE_H
#define YAWM_WAVE_H

#include "WaveHeader.h"
#include "WaveFormatChunk.h"
#include <memory>
#include <iostream>

enum ExtractionType {
    PCM_TO_FILE = 0,
    PCM_STREAM
};

class Wave {
public:
    Wave(const std::string path, const ExtractionType extract, const uint32_t byteInterval=0);
    void hi();
private:
    std::unique_ptr<WaveHeader>      _header;
    std::unique_ptr<WaveFormatChunk> _formatChunk;
};

#endif // Defines Wave.h
