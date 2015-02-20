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

unsigned int joystick_mapping[] =
{
	0, 0, 0, 0,
	0, 1,
	4, 5,
	7, 6
};

const float JOYSTICK_THRESHOLD = 10;

InputController::InputController(Character* c):
	character(c),
	eventSource(ES_KEYBOARD)
{
}

void InputController::Update()
{
	if(eventSource == ES_KEYBOARD)
		keyboardAction();
	else
		joystickAction();
}

void InputController::SetEventSource(EventSource source, unsigned int id)
{
	eventSource = source;
	joystickId = id;
}

void InputController::keyboardAction()
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
		actionAPressed();
	else
		actionAReleased();
	
	if(sf::Keyboard::isKeyPressed(keys_mapping[KEY_B]))
		actionBPressed();
	else
		actionBReleased();

	if(sf::Keyboard::isKeyPressed(keys_mapping[KEY_R]))
		actionRPressed();
	else
		actionRReleased();
	
	if(sf::Keyboard::isKeyPressed(keys_mapping[KEY_L]))
		actionLPressed();
	else
		actionLReleased();
}

void InputController::joystickAction()
{
	if(sf::Joystick::isConnected(joystickId))
	{
		float xAxis = sf::Joystick::getAxisPosition(joystickId, sf::Joystick::PovX);

		if(xAxis < -JOYSTICK_THRESHOLD)
		{
			actionRightReleased();
			actionLeftPressed();
		}
		else if(xAxis > JOYSTICK_THRESHOLD)
		{
			actionLeftReleased();
			actionRightPressed();
		}
		else
		{
			actionLeftReleased();
			actionRightReleased();
		}

		if(sf::Joystick::isButtonPressed(joystickId, joystick_mapping[KEY_A]))
			actionAPressed();
		else
			actionAReleased();
		
		if(sf::Joystick::isButtonPressed(joystickId, joystick_mapping[KEY_B]))
			actionBPressed();
		else
			actionBReleased();

		if(sf::Joystick::isButtonPressed(joystickId, joystick_mapping[KEY_R]))
			actionRPressed();
		else
			actionRReleased();
		
		if(sf::Joystick::isButtonPressed(joystickId, joystick_mapping[KEY_L]))
			actionLPressed();
		else
			actionLReleased();
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

void InputController::actionAPressed()
{
	character->Jump();
}

void InputController::actionAReleased()
{
	character->ReleaseJump();
}

void InputController::actionBPressed()
{
	if((eventSource == ES_KEYBOARD && sf::Keyboard::isKeyPressed(keys_mapping[KEY_UP]))
	|| (eventSource == ES_JOYSTICK && sf::Joystick::getAxisPosition(joystickId, sf::Joystick::PovY) < -JOYSTICK_THRESHOLD))
		character->UseRedSoul();
	else
		character->Attack();
}

void InputController::actionBReleased()
{
	character->ReleaseAttack();
}
void InputController::actionRPressed()
{
	character->UseBlueSoul();
}

void InputController::actionRReleased()
{
	character->ReleaseBlueSoul();
}

void InputController::actionLPressed()
{
	character->BackDash();
}

void InputController::actionLReleased()
{
	character->ReleaseBackDash();
}

