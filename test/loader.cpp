#include "loader.h"

/**
	This class loads the raw hex data from the specific file and
	returns it to the Chip8 class as a ROM ready to write to memory
*/

Loader::Loader(std::string filepath) {
	std::ifstream ROM(filepath);
	u8 byte;

	if (!ROM.is_open()) {
		std::cout << "CANNOT READ ROM" << std::endl;
	}
	else {
		while (!ROM.eof()) {
			ROM >> std::noskipws >> std::hex >> byte;
			ROMsource.push_back(byte);
		}
	}
}

std::vector<u8> Loader::getROM() {
	return ROMsource;
}