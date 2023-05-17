#include "chip8.h"

/**
    This class is the main application loop of the Chip8. Handles calling everything the VM needs
    such as opcode execution, calls to render to the screen and memory retrieval
*/

Chip8::Chip8() {
    s = new Screen();
    m = new Memory();
    r = new Registers;
    k = new Keyboard;

    std::cout << "Loading default sprites to memory..." << std::endl;
    memcpy(m->memory, DEFAULT_SPRITE, sizeof(DEFAULT_SPRITE));

    std::cout << "Loading ROM..." << std::endl;
    Loader ROMloader("C:/Users/CMarkakis/source/repos/Chip8-Emulator/test/chip8-roms-master/games/Space-Invaders-[David Winter]-(alt).ch8");
    ROM = ROMloader.getROM();
    memcpy(&m->memory[0x200], ROM.data(), ROM.size());

    r->pc = 0x200;
    r->sp = stack.size();

    r->V[1] = 200;
    r->V[2] = 56;
    processOp(8124);
    std::cout << std::hex << r->V[0xF] << std::endl;
    std::cout << std::hex << r->V[0x1] << std::endl;
}

Chip8::~Chip8() {
    std::cout << "Shutting Down..." << std::endl;
    delete s;
    delete m;
    delete r;
    delete k;
}

void Chip8::run() {

    sf::RenderWindow window({SCREEN_WIDTH, SCREEN_HEIGHT}, "Chip8 Emulator", sf::Style::Default, sf::ContextSettings(0, 0, 8));
    while (window.isOpen()) {
        window.clear(sf::Color::Black);

        input(&window);

        render(&window);

        window.display();

        //processOp(getOp());
        //r->pc += 2;
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

u16 Chip8::getOp() {
    u8 byte1 = m->getMem(r->pc);
    u8 byte2 = m->getMem(r->pc + 1);
    return byte1 << 8 | byte2;
}

void Chip8::processOp(u16 opcode) {
    
    // This switch statement will handle any opcodes that don't take arguments
    switch (opcode) {

        // CLS - 00E0 - Clear Display
        case 0x00E0:
        {
            s->screenClear();
            break;
        }

        // RET - 00EE - Return from Subroutine
        case 0x00EE:
        {
            r->pc = stack.top();
            stack.pop();
            r->sp--;
            break;
        }
    }

    // This switch statement handles any opcodes that do take arguments
    switch (opcode >> 12) {

        // JP - 1nnn - Jump to location nnn
        case 0x1:
        {
            u16 nnn = opcode & 0x0FFF;
            r->pc = nnn;
            break;
        }

        // CALL - 2nnn - Call subroutine at nnn
        case 0x2:
        {
            r->sp++;
            stack.push(r->pc);
            u16 nnn = opcode & 0x0FFF;
            r->pc = nnn;
            break;
        }

        // SE - 3xkk - Skip next instruction if V[x] == kk
        case 0x3:
        {
            u8 x = (opcode & 0x0F00) >> 8;
            u8 kk = (opcode & 0x00FF);
            if (r->V[x] == kk) {
                r->pc += 2;
            }
            break;
        }

        // SNE - 4xkk - Skip next instruction if V[x] != kk
        case 0x4:
        {
            u8 x = (opcode & 0x0F00) >> 8;
            u8 kk = (opcode & 0x00FF);
            if (r->V[x] != kk) {
                r->pc += 2;
            }
            break;
        }

        // SE - 5xy0 - Skip next instruction if V[x] == V[y]
        case 0x5:
        {
            u8 x = (opcode & 0x0F00) >> 8;
            u8 y = (opcode & 0x00F0) >> 4;
            if (r->V[x] == r->V[y]) {
                r->pc += 2;
            }
            break;
        }

        // LD - 6xkk - Set V[x] = kk
        case 0x6:
        {
            u8 x = (opcode & 0x0F00) >> 8;
            u8 kk = (opcode & 0x00FF);

            r->V[x] = kk;
            break;
        }

        // LD - 7xkk - Set V[x] = kk
        case 0x7:
        {
            u8 x = (opcode & 0x0F00) >> 8;
            u8 kk = (opcode & 0x00FF);

            r->V[x] += kk;
            break;
        }

        // If opcode starts with an 8, goto function dedicated for those cases
        case 0x8:
        {
            processOp8(opcode);
        }
    }
}

void Chip8::processOp8(u16 opcode) {

    switch (opcode & 0x000F) {
        
        // LD - 8xy0 - Set V[x] = V[y]
        case 0:
        {
            u8 x = (opcode & 0x0F00) >> 8;
            u8 y = (opcode & 0x00F0) >> 4;
            r->V[x] = r->V[y];
            break;
        }

        // OR - 8xy1 - Set V[x] = V[x] OR V[y]
        case 1:
        {
            u8 x = (opcode & 0x0F00) >> 8;
            u8 y = (opcode & 0x00F0) >> 4;
            r->V[x] |= r->V[y];
            break;
        }

        // AND - 8xy2 - Set V[x] = V[x] AND V[y]
        case 2:
        {
            u8 x = (opcode & 0x0F00) >> 8;
            u8 y = (opcode & 0x00F0) >> 4;
            r->V[x] &= r->V[y];
            break;
        }

        // XOR - 8xy3 - Set V[x] = V[x] XOR V[y]
        case 3:
        {
            u8 x = (opcode & 0x0F00) >> 8;
            u8 y = (opcode & 0x00F0) >> 4;
            r->V[x] ^= r->V[y];
            break;
        }

        // ADD - 8xy4 - Set V[x] = V[x] + V[y], If the result is greater than 8 bits
        // V[F] is set to 1, otherwise 0. Only the lowest 8 bits of the result are kept, and stored in V[x]
        case 4:
        {
            u8 x = (opcode & 0x0F00) >> 8;
            u8 y = (opcode & 0x00F0) >> 4;
            u16 result = r->V[x] + r->V[y];

            if (result > 0xFF) {
                r->V[0xF] = 1;
            }
            else {
                r->V[0xF] = 0;
            }
            r->V[x] = (result & 0xFF);

            break;
        }

    }
}