#pragma once
#include "memory.h"
#include "registers.h"
#include "screen.h"

class Chip8 {

private:

public:

	Memory m;
	Registers r;
	Screen s;

	Chip8();
	~Chip8();

};
