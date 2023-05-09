#include "loader.h"

Loader::Loader(std::string filepath) {
	std::ifstream ROM(filepath, std::ios::binary);

	if (!ROM.is_open()) {
		std::cout << "CANNOT READ ROM" << std::endl;
	}
	else {
		
	}
}

std::vector<u16> Loader::getROM() {
	return ROMsource;
}