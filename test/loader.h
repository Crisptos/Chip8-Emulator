#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <iostream>

#include "config.h"


class Loader {

public:

	Loader(std::string filepath);
	std::vector<u8> getROM();

	std::vector<u8> ROMsource;
};
