#pragma once
#include "config.h"


typedef struct Registers {
	u8 V[0x10];
	u16 I;
	u16 pc;
	u8 sp;
};