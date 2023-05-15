#include "loader.h"

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