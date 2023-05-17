#pragma once
#include "config.h"

/** 
	The Registers struct contains the variables needed for runtime execution of the Chip8 machine code
*/

typedef struct Registers {
	u8 V[0x10];	// 16 General Purpose V Registers
	u16 I;		// 16 bit I register

	u8 sound;	// Sound Timer
	u8 delay;	// Delay Timer

	u16 pc;		// Program Counter
	u8 sp;		// Stack Pointer
};