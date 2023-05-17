#include "memory.h"
#include <assert.h>

/**
	This class represents the active memory of the Chip8. Memory is stored in an array of 8 bit values
	Includes Getters and Setters that check index bounds
*/

Memory::Memory() {
	std::cout << "Setting memory to 0 (empty)" << std::endl;
	memset(memory, 0, sizeof(memory));
}

bool Memory::memBounds(int i) {
	assert(i <= 4095 && i >= 0);
	return true;
}