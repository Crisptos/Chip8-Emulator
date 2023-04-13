#include <iostream>
#include <assert.h>
#include "config.h"
#include "screen.h"

Screen::Screen() {
	for (int y = 0; y < SCREEN_HEIGHT/RES_MULTIPLIER; y++) {
		for (int x = 0; x < SCREEN_WIDTH/RES_MULTIPLIER; x++) {
			pixelBuffer[y][x] = 0;
		}
	}
	std::cout << "Screen Initialized..." << std::endl;
}

bool Screen::drawBounds(int y, int x) {
	assert(y <= 31 && x <= 63 && y >= 0 && x >= 0);
	return true;
}

Screen::~Screen() {

}

