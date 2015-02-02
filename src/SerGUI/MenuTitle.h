#ifndef MENUTITLE_H
#define MENUTITLE_H

#include <SFML/Graphics.hpp>

/** The first screen you see in the game **/
class MenuTitle
{
    public:
        MenuTitle();
        void Run();
    protected:
        void goToNextScreen();
        sf::Sprite background;
        sf::Text text;
};

#endif // MENUTITLE_H
