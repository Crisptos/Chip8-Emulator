#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "memory.h"

int main()
{
    sf::RenderWindow window({ 640, 480 }, "CHIP8", sf::Style::Default, sf::ContextSettings(0, 0, 8));
  

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        window.display();
    }
}