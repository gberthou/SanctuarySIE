#ifndef SERGUI_H_INCLUDED
#define SERGUI_H_INCLUDED

#include <SFML/Graphics.hpp>

namespace SerGUI
{
    extern unsigned int SCREEN_WIDTH;
    extern unsigned int SCREEN_HEIGHT;

    extern sf::Font fontMenu1;

    extern sf::RenderWindow window;

    bool Load();
    void Free();
}


#endif // SERGUI_H_INCLUDED
