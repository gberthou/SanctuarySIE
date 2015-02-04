#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Character.h"

enum KeyMapping
{
    KEY_LEFT, KEY_UP, KEY_DOWN, KEY_RIGHT,
    KEY_A, KEY_B,
    KEY_L, KEY_R,
    KEY_START, KEY_SELECT,
    KEY_COUNT // must be the last
};

extern sf::Keyboard::Key keys_mapping[];

class InputController
{
    public:
        InputController(Character* c);
        void Update(sf::Event const& event);

    protected:
        void actionLeft();
        void actionRight();
        void actionUp();
        void actionDown();
        void actionA();
        void actionB();

        Character* character;

    private:

};

#endif // INPUT_CONTROLLER_H
