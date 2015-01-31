#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Character.h"

enum KeyMapping {KEY_LEFT, KEY_UP, KEY_DOWN, KEY_RIGHT, KEY_A, KEY_B,
    KEY_L, KEY_R, KEY_START, KEY_SELECT, KEY_COUNT};
sf::Keyboard::Key keys[] = {sf::Keyboard::Left};

class InputController
{
    public:
        void Update(sf::Event const& event);

    protected:
        void actionLeft();
        Character* c;

    private:

};

#endif // INPUT_CONTROLLER_H
