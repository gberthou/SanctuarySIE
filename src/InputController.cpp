#include "InputController.h"
enum KeyMapping
{
    KEY_LEFT, KEY_UP, KEY_DOWN, KEY_RIGHT,
    KEY_A, KEY_B,
    KEY_L, KEY_R,
    KEY_START, KEY_SELECT,
    KEY_COUNT // must be the last
};
sf::Keyboard::Key keys_mapping[] =
{
    sf::Keyboard::Left,sf::Keyboard::Up, sf::Keyboard::Down,sf::Keyboard::Right,
    sf::Keyboard::Space, sf::Keyboard::X,
    sf::Keyboard::S, sf::Keyboard::R,
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
            actionLeft();
        if(sf::Keyboard::isKeyPressed(keys_mapping[KEY_RIGHT]))
            actionRight();
        if(sf::Keyboard::isKeyPressed(keys_mapping[KEY_UP]))
            actionUp();
        if(sf::Keyboard::isKeyPressed(keys_mapping[KEY_DOWN]))
            actionDown();

        if(sf::Keyboard::isKeyPressed(keys_mapping[KEY_A]))
            actionA();
    }
}

void InputController::actionLeft()
{
    character->Walk(sf::Vector2f(-1.f,0.f));
}

void InputController::actionRight()
{
    character->Walk(sf::Vector2f(1.f,0.f));
}

void InputController::actionUp()
{
}

void InputController::actionDown()
{
}

void InputController::actionA()
{
     character->Walk(sf::Vector2f(0.f,-1.f));
}

void InputController::actionB()
{
}
