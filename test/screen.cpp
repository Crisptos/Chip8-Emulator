#include <iostream>
#include <assert.h>
#include "screen.h"

Screen::Screen() {
	memset(pixelBuffer, 0, sizeof(pixelBuffer));
}

bool Screen::drawBounds(int y, int x) {
	assert(y <= 31 && x <= 63 && y >= 0 && x >= 0);
	return true;
}

