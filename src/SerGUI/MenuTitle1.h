#ifndef MENUTITLE1_H
#define MENUTITLE1_H

#include <SFML/Graphics.hpp>

class MenuTitle1
{

    public:
        MenuTitle1();
		bool Load(void);		
        void Run(void);
    protected:
        void goToNextScreen(void);
		sf::Texture texBackground;
		sf::Texture texCover;
		sf::Texture texBat;
        sf::Text text;
};

#endif // MENUTITLE1_H

