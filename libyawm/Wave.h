#ifndef YAWM_WAVE_H
#define YAWM_WAVE_H

#include "WaveHeader.h"
#include "WaveFormatChunk.h"

#include <iostream>
#include <fstream>
#include <memory>

class Wave {
public:
    Wave(const std::string path, const uint32_t byteInterval=512);

private:
    bool openFile(const std::string& path);
    std::shared_ptr<char> getBytes(uint32_t bytes);

    std::fstream _file;
    std::unique_ptr<WaveHeader>      _header;
    std::unique_ptr<WaveFormatChunk> _formatChunk;
};

#endif // Defines Wave.h
