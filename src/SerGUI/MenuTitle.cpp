#include "MenuTitle.h"
#include "MenuSelectSave.h"
#include "SerGUI.h"

MenuTitle::MenuTitle()
{
    background.setTexture(SerGUI::texMenuTitleBG);
    text.setFont(SerGUI::fontMenu1);
    text.setCharacterSize(24);
    text.setString(SerGUI::TXT_TITLE_SCREEN);
    text.setOrigin(text.getGlobalBounds().width/2.f,
                   text.getGlobalBounds().height*2.f);
    text.setPosition(SerGUI::window.getSize().x/2.f,SerGUI::window.getSize().y-10.f);
}

void MenuTitle::Run()
{
    while(SerGUI::window.isOpen())
	{
		sf::Event event;
		while(SerGUI::window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				SerGUI::window.close();
            if(event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                    SerGUI::window.close();
				else if (event.key.code == keys_mapping[KEY_A]
                     || event.key.code == keys_mapping[KEY_START])
                {
                    goToNextScreen();
                }
            }
		}

		SerGUI::window.clear(sf::Color::Black);
		SerGUI::window.draw(background);
		SerGUI::window.draw(text);

		SerGUI::window.display();
	}
}

void MenuTitle::goToNextScreen()
{
    MenuSelectSave menu;
    menu.Run();
}
