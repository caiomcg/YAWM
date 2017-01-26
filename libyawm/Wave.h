#ifndef YAWM_WAVE_H
#define YAWM_WAVE_H

#include "WaveHeader.h"
#include "WaveFormatChunk.h"
#include <memory>

class Wave {
public:
    Wave();

private:
    std::unique_ptr<WaveHeader>      _header;
    std::unique_ptr<WaveFormatChunk> _formatChunck;
};

#endif // Defines Wave.h
