#pragma once


class Screen {

private:


public:
	int pixelBuffer[32][64];	// default CHIP8 screen dimensions are 64x32

	Screen();
	void draw(int y, int x) { if(drawBounds(y,x)) pixelBuffer[y][x] = 1; }
	int isDrawn(int y, int x) { if(drawBounds(y,x)) return pixelBuffer[y][x]; }
	bool drawBounds(int y, int x);
	~Screen();
};
