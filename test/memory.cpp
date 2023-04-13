#include "memory.h"
#include <assert.h>

Memory::Memory() {
	std::cout << "Setting memory to 0 (empty)" << std::endl;
	memset(memory, 0, sizeof(memory));
}

bool Memory::memBounds(int i) {
	assert(i <= 4095 && i >= 0);
	return true;
}