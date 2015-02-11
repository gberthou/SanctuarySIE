#include "SerGUI.h"
#ifdef DEBUG
#include <iostream>
#endif
#include <string>

namespace SerGUI
{
    const unsigned int MIN_SCREEN_WIDTH = 800;
    const unsigned int MIN_SCREEN_HEIGHT = 600;
    unsigned int SCREEN_WIDTH = MIN_SCREEN_WIDTH;
    unsigned int SCREEN_HEIGHT = MIN_SCREEN_HEIGHT;
    unsigned int FPS = 60;

    const sf::String WINDOW_TITLE("Sanctuary : Shrouded in Evil ");

    sf::RenderWindow window;

    sf::Font fontMenu1;

    bool Load()
    {
        if(!fontMenu1.loadFromFile("font/EnglishTowne.ttf"))
        {
            #ifdef DEBUG
            std::cout<<"Fail while loading font"<<std::endl;
            #endif
            return false;
        }
        /*window.create(sf::VideoMode(SerGUI::SCREEN_WIDTH,SerGUI::SCREEN_HEIGHT),
                      SerGUI::WINDOW_TITLE,sf::Style::Default);
        */
        return true;
    }
    void Free()
    {

    }
}

