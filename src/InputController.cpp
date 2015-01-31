#include "InputController.h"


void InputController::Update(sf::Event const& event)
{
    for(int i=0;i<KEY_COUNT;++i)
    {
        if(sf::Keyboard::isKeyPressed(keys[KEY_LEFT]))
        {
            actionLeft();
        }
    }
}

void InputController::actionLeft()
{

}
