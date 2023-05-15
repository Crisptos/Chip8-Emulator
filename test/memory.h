#pragma once
#include "config.h"

class Memory {

public:
	Memory();
	u8 memory[4096];			// array represenation of Chip8 memory. 0x0 - 0xFFF
	bool memBounds(int i);	// Helper function to make sure we stay within bounds
	u8 getMem(int i) { if (memBounds(i)) return memory[i]; }		// getter
	void setMem(int i, u8 e) { if(memBounds(i)) memory[i] = e; }	// setter
};
