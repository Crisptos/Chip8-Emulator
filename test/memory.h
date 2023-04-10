#pragma once
#include "config.h"

class Memory {

private:
	u32 memory[4096];			// array represenation of Chip8 memory. 0x0 - 0xFFF
	bool memBounds(int i);	// Helper function to make sure we stay within bounds
	

public:
	u32 getMem(int i) { if (memBounds(i)) return memory[i]; }		// getter
	void setMem(int i, u32 e) { if(memBounds(i)) memory[i] = e; }	// setter
};
