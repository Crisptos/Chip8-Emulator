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

bool Screen::drawSprite(int y, int x, const u8 SPRITE[], int n) {

	bool pixel_clipped = false;

	for (int ly = 0; ly < n; ly++) {
		char s = SPRITE[ly];
		for (int lx = 0; lx < 8; lx++) {
			if ((s & (0b10000000 >> lx)) == 0)
				continue;
			if (pixelBuffer[(ly + y) % 32][(lx + x) % 64] == 1)
				pixel_clipped = true;

			pixelBuffer[(ly + y)%32][(lx + x)%64] ^= 1;
		}
	}

	return pixel_clipped;
}

void Screen::screenClear() {
	for (int y = 0; y < SCREEN_HEIGHT / RES_MULTIPLIER; y++) {
		for (int x = 0; x < SCREEN_WIDTH / RES_MULTIPLIER; x++) {
			pixelBuffer[y][x] = 0;
		}
	}
}

Screen::~Screen() {

}

