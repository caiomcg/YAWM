#include <iostream>
#include <fstream>
#include <cstdint>
#include <getopt.h>
#include "../libyawm/Wave.h"

std::string filePath;
std::string extractedFileName;
std::string address;

bool pcmtofile = false;
bool pcmtostream = false;

void usage(void) {
	std::cout << "\033[1;37mNAME\033[0m" << std::endl;
    std::cout << "        YAWM - Yet Another Wave Manipulator." << std::endl;
	std::cout << "\033[1;37mSYNOPSIS\033[0m" << std::endl;
    std::cout << "        YAWM <OPTIONS>" << std::endl;
	std::cout << "\033[1;37mDESCRIPTION\033[0m" << std::endl;
    std::cout << "        Extract Wave file data to file or serve bytes for streaming." << std::endl;
	std::cout << "        --file=[FILE_PATH]" << std::endl;
    std::cout << "            File to manipulate." << std::endl;
    std::cout << "        --pcmtofile=[EXTRACTED_FILE_NAME]" << std::endl;
    std::cout << "            Extract the audio data to a file." << std::endl;
	std::cout << "        --pcmstream=[IP:PORT]" << std::endl;
    std::cout << "            Stream the audio data" << std::endl;
    std::cout << "\033[1;37mEXIT STATUS\033[0m" << std::endl;
    std::cout << "        0 - If ok" << std::endl;
    std::cout << "        1 - If a problem occured" << std::endl;
    std::cout << "\033[1;37mUSE EXAMPLE\033[0m" << std::endl;
    std::cout << "        \033[0;35mYAWM --file=file.wav --pcmtofile\033[0m" << std::endl;
}

bool parseArguments (int argc, char** argv) {
    int long_index = 0;
    int opt        = 0;

    static struct option long_options[] = {
        {"pcmtofile", required_argument, 0, 'p'},
        {"pcmtostream", required_argument, 0, 's'},
        {"file", required_argument, 0, 'f'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "f:p:s:", long_options, &long_index)) != -1) {
        switch (opt) {
            case 'f': //FILE
				filePath = optarg;
                break;
            case 'p': //PCM TO FILE
                extractedFileName = optarg;
				pcmtofile = true;
                break;
            case 's': //PCM STREAM
                address = optarg;
				pcmtostream = true;
                break;
			default:
				return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
	if (argc <= 1) {
		usage();
		return 1;
	}

	if (!parseArguments(argc, argv)) {
		usage();
		return 1;
	}

	if (pcmtofile && pcmtostream) {
		usage();
		return 1;
	}

	std::unique_ptr<Wave> wave(new Wave(filePath));



	return 0;
}
