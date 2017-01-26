#include "Wave.h"

Wave::Wave(const std::string path, const uint32_t byteInterval) {
    if (!openFile(path)) {
        std::cerr << "Throw Exception" << std::endl;
    }

    std::shared_ptr<char> data = getBytes(5);

    data.get()[4] = '\0';
    std::cout << "RIFF? " << data.get() << std::endl;
}

bool Wave::openFile(const std::string& path) {
    _file.open(path, std::ios::in | std::ios::binary);
    return _file.is_open() ? true : false;
}

std::shared_ptr<char> Wave::getBytes(uint32_t bytes) {
    std::shared_ptr<char> packet(new char[bytes]);
    _file.read(packet.get(), bytes);
    return packet;
}
