#ifndef MENUTITLE1_H
#define MENUTITLE1_H

#include <SFML/Graphics.hpp>

enum MenuTitle1Code
{
	EXIT,
	MENU_SELECT_SAVE
};

class MenuTitle1
{

    public:
        MenuTitle1();
		bool Load(void);		
        MenuTitle1Code Run(void);
    protected:
		sf::Texture texBackground;
		sf::Texture texCover;
		sf::Texture texBat;
        sf::Text text;
};

#endif // MENUTITLE1_H

