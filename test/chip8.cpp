#include "chip8.h"

Chip8::Chip8() {

}

Chip8::~Chip8() {
	m.~Memory();
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
    for (int x = 0; x < ) {

    }

}