#pragma once

/** 
	This class loads the raw hex data from the specific file and 
	returns it to the Chip8 class as a ROM ready to write to memory
*/

#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <iostream>

#include "config.h"


class Loader {

public:

	Loader(std::string filepath);	// Constructor loads the hex data
	std::vector<u8> getROM();		// Returns the ROM

	std::vector<u8> ROMsource;		// Saves each 1 byte hex value into a vector of u8's
};
