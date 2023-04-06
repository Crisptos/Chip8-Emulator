#pragma once
#include "config.h"

class Registers {

private:
	u8* V;	// general purpose register, Chip8 uses v[0] - v[f].
			// v[f] should not be used by any program and only works as a flag
			// for some instructions

	u16 I;	// used for memory addresses
	u16 pc;	// program counter register
	u8 sp;	// stack pointer register

public:

	Registers();
	~Registers();


};