#pragma once
#include "memory.h"
#include "registers.h"

class Chip8 {

private:

public:

	Memory m;
	Registers r;

	Chip8();
	~Chip8();

};
