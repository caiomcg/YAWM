#ifndef YAWM_WAVEHEADER_H
#define YAWM_WAVEHEADER_H

#include <cstdint>

class WaveHeader {
public:
    WaveHeader(const char* headerBytes = nullptr);
    bool isWave() const;
private:
    char     _sGroupID[4];
    char     _sRiffType[4];
    uint32_t _dwFileLength;
};

#endif // Defines WaveHeader.h
