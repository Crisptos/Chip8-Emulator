#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

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
	void run();
	void input(sf::RenderWindow* window);
	void render(sf::RenderWindow* window);
	~Chip8();

};
