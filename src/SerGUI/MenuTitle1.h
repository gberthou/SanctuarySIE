#ifndef MENUTITLE1_H
#define MENUTITLE1_H

#include <SFML/Graphics.hpp>

class MenuTitle1
{

    public:
        MenuTitle1();
        void Run();
    protected:
        void goToNextScreen();
        sf::Sprite background;
        sf::Text text;
};

#endif // MENUTITLE1_H

