#include "MenuTitle1.h"
#include "MenuSelectSave.h"
#include "SerGUI.h"
#include "Bat.h"

const unsigned int NBATS = 333;

MenuTitle1::MenuTitle1()
{
    background.setTexture(SerGUI::texMenuTitle1BG);
    text.setFont(SerGUI::fontMenu1);
    text.setCharacterSize(24);
    text.setString(SerGUI::TXT_TITLE_SCREEN);
    text.setOrigin(text.getGlobalBounds().width/2.f,
                   text.getGlobalBounds().height*2.f);
    text.setPosition(SerGUI::window.getSize().x/2.f,SerGUI::window.getSize().y-10.f);
}

void MenuTitle1::Run()
{
	sf::Texture batTexture;
	Bat *bats[NBATS];

	batTexture.loadFromFile("img/sergui/bat.png");

	for(unsigned int i = 0; i < NBATS; ++i)
	{
		bats[i] = new Bat(batTexture);
	}

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

		for(unsigned int i = 0; i < NBATS; ++i)
			bats[i]->Update();

		SerGUI::window.clear(sf::Color::Black);
		SerGUI::window.draw(background);
		
		for(unsigned int i = 0; i < NBATS; ++i)
			SerGUI::window.draw(*bats[i]);
		
		SerGUI::window.draw(text);

		SerGUI::window.display();
	}

	for(unsigned int i = 0; i < NBATS; ++i)
		delete bats[i];
}

void MenuTitle1::goToNextScreen()
{
    MenuSelectSave menu;
    menu.Run();
}
