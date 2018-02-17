#include "Wave.h"

Wave::Wave(const std::string& path, const uint32_t byteInterval) {
    if (!openFile(path)) {
        std::cerr << "Throw Exception" << std::endl;
    }

    this->header_ = std::make_unique<WaveHeader>(this->getBytes(44).get());
}

bool Wave::openFile(const std::string& path) {
    file_.open(path, std::ios::in | std::ios::binary);
    return file_.is_open() ? true : false;
}



std::shared_ptr<uint8_t> Wave::getBytes(uint32_t bytes) {
    std::unique_ptr<uint8_t> packet(new uint8_t[bytes]);
    file_.read((char*)packet.get(), bytes);
    return std::move(packet);
}
