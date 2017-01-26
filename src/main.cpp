#include <iostream>
#include <fstream>
#include <cstdint>
#include "../libyawm/Wave.h"

void usage(void) {
	std::cout << "\033[1;37mNAME\033[0m" << std::endl;
    std::cout << "        YAWM - Yet Another Wave Manipulator." << std::endl;
	std::cout << "\033[1;37mSYNOPSIS\033[0m" << std::endl;
    std::cout << "        YAWM [FILE_PATH]" << std::endl;
    std::cout << "\033[1;37mEXIT STATUS\033[0m" << std::endl;
    std::cout << "        0 - If ok" << std::endl;
    std::cout << "        1 - If a problem occured" << std::endl;
    std::cout << "\033[1;37mUSE EXAMPLE\033[0m" << std::endl;
    std::cout << "        \033[0;35mYAWM file.wav\033[0m" << std::endl;
}

int main(int argc, const char** argv) {
	if (argc <= 1) {
		usage();
		return 1;
	}

	return 0;
}
