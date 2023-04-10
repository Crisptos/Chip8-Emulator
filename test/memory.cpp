#include "memory.h"
#include <assert.h>

bool Memory::memBounds(int i) {
	assert(i <= 4095 && i >= 0);
	return true;
}