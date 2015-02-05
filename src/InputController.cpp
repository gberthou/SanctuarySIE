#include <iostream>

#include "InputController.h"
#include "Orientation.h"

using namespace std;

sf::Keyboard::Key keys_mapping[] =
{
    sf::Keyboard::Left,sf::Keyboard::Up, sf::Keyboard::Down,sf::Keyboard::Right,
    sf::Keyboard::Z, sf::Keyboard::A,
    sf::Keyboard::Q, sf::Keyboard::S,
    sf::Keyboard::Return,sf::Keyboard::BackSpace
};

InputController::InputController(Character* c)
{
    character = c;
}

void InputController::Update(sf::Event const& event)
{
    for(int i=0;i<KEY_COUNT;++i)
    {
        if(sf::Keyboard::isKeyPressed(keys_mapping[KEY_LEFT]))
            actionLeftPressed();
		else
			actionLeftReleased();
        
		if(sf::Keyboard::isKeyPressed(keys_mapping[KEY_RIGHT]))
            actionRightPressed();
		else
			actionRightReleased();

        if(sf::Keyboard::isKeyPressed(keys_mapping[KEY_UP]))
            actionUp();
        if(sf::Keyboard::isKeyPressed(keys_mapping[KEY_DOWN]))
            actionDown();

        if(sf::Keyboard::isKeyPressed(keys_mapping[KEY_A]))
            actionA();
        
		if(sf::Keyboard::isKeyPressed(keys_mapping[KEY_B]))
            actionB();
    }
}

void InputController::actionLeftPressed()
{
    character->Walk(ORIENTATION_LEFT);
}

void InputController::actionLeftReleased()
{
    character->StopWalking(ORIENTATION_LEFT);
}

void InputController::actionRightPressed()
{
    character->Walk(ORIENTATION_RIGHT);
}

void InputController::actionRightReleased()
{
    character->StopWalking(ORIENTATION_RIGHT);
}

void InputController::actionUp()
{
}

void InputController::actionDown()
{
}

void InputController::actionA()
{
	character->Jump();
}

void InputController::actionB()
{
	if(sf::Keyboard::isKeyPressed(keys_mapping[KEY_UP]))
		character->UseRedSoul();
	else
		character->Attack();
}
