#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Character.h"

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
