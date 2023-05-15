#include "chip8.h"

Chip8::Chip8() {
    s = new Screen();
    m = new Memory();
    r = new Registers;

    std::cout << "Loading default sprites to memory..." << std::endl;
    memcpy(m->memory, DEFAULT_SPRITE, sizeof(DEFAULT_SPRITE));

    std::cout << "Loading ROM..." << std::endl;
    Loader ROMloader("C:/Users/CMarkakis/source/repos/Chip8-Emulator/test/chip8-roms-master/games/Space-Invaders-[David Winter]-(alt).ch8");
    ROM = ROMloader.getROM();
    memcpy(&m->memory[0x200], ROM.data(), ROM.size());
}

Chip8::~Chip8() {
    std::cout << "Shutting Down..." << std::endl;
    delete s;
    delete m;
    delete r;
}

void Chip8::run() {

    sf::RenderWindow window({SCREEN_WIDTH, SCREEN_HEIGHT}, "Chip8 Emulator", sf::Style::Default, sf::ContextSettings(0, 0, 8));
    while (window.isOpen()) {
        window.clear(sf::Color::Black);

        input(&window);
        render(&window);

        window.display();
    }
}

void Chip8::input(sf::RenderWindow* window) {

    sf::Event event;
    while (window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
        }
    }
}

void Chip8::render(sf::RenderWindow* window) {
    for (int y = 0; y < SCREEN_HEIGHT/RES_MULTIPLIER; y++) {
        for (int x = 0; x < SCREEN_WIDTH/RES_MULTIPLIER; x++) {
            if (s->pixelBuffer[y][x] == 1) {
                sf::RectangleShape pixel;
                pixel.setSize(sf::Vector2f(10.0, 10.0));
                pixel.setPosition(x*RES_MULTIPLIER, y*RES_MULTIPLIER);
                window->draw(pixel);
            }
        }
    }
}