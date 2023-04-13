#include "chip8.h"

Chip8::Chip8() {
    s = new Screen();
    m = new Memory();
    r = new Registers();

}

Chip8::~Chip8() {
    delete[] s;
    delete[] m;
    delete[] r;
}

void Chip8::run() {

    sf::RenderWindow window({SCREEN_WIDTH, SCREEN_HEIGHT}, "Chip8 Emulator", sf::Style::Default, sf::ContextSettings(0, 0, 8));

    s->draw(0,0);
    s->draw(1,1);

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
                pixel.setPosition(y*RES_MULTIPLIER, x*RES_MULTIPLIER);
                window->draw(pixel);
            }
        }
    }

}