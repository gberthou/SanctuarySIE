#include <vector>

#include "InputController.h"
#include "MenuTitle1.h"
#include "SerGUI.h"
#include "Bat.h"

const sf::String S_BACKGROUND("img/sergui/title1.png");
const sf::String S_COVER("img/sergui/title1cover.png");
const sf::String S_BAT("img/sergui/bat.png");

const unsigned int NBATS = 333;

MenuTitle1::MenuTitle1()
{
    text.setFont(SerGUI::fontMenu1);
    text.setCharacterSize(24);
    text.setString(SerGUI::TXT_TITLE_SCREEN);
    text.setOrigin(text.getGlobalBounds().width/2.f,
                   text.getGlobalBounds().height*2.f);
    text.setPosition(SerGUI::window.getSize().x/2.f,SerGUI::window.getSize().y-10.f);
}

bool MenuTitle1::Load(void)
{
	return texBackground.loadFromFile(S_BACKGROUND)
		&& texCover.loadFromFile(S_COVER)
		&& texBat.loadFromFile(S_BAT);
}

MenuTitle1Code MenuTitle1::Run(void)
{
	MenuTitle1Code ret = EXIT;

	sf::Sprite background(texBackground);
	sf::Sprite cover(texCover);

	std::vector<Bat*> inside(NBATS);
	std::vector<Bat*> outside;

	for(unsigned int i = 0; i < NBATS; ++i)
	{
		inside[i] = new Bat(texBat);
	}

    while(SerGUI::window.isOpen() && ret == EXIT)
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
					ret = MENU_SELECT_SAVE;
                }
            }
		}

		// Make the bats pass from the inside collection to the outside collection
		for(std::vector<Bat*>::iterator it = inside.begin(); it != inside.end();)
		{
			(*it)->Update();
			if((*it)->IsOutside())
			{
				std::vector<Bat*>::iterator tmp = it;
				outside.push_back(*tmp);
				it = inside.erase(tmp);
			}
			else
				++it;
		}

		for(unsigned int i = 0; i < outside.size(); ++i)
			outside[i]->Update();

		SerGUI::window.clear(sf::Color::Black);
		
		// First draw the background
		SerGUI::window.draw(background);
		
		// Then the "inside" bats
		for(unsigned int i = 0; i < inside.size(); ++i)
			SerGUI::window.draw(*inside[i]);

		// Then the cover
		if(inside.size() != 0)
			SerGUI::window.draw(cover);

		// Then the "outside" bats
		for(unsigned int i = 0; i < outside.size(); ++i)
			SerGUI::window.draw(*outside[i]);

		SerGUI::window.draw(text);

		SerGUI::window.display();
	}

	for(unsigned int i = 0; i < inside.size(); ++i)
		delete inside[i];

	for(unsigned int i = 0; i < outside.size(); ++i)
		delete outside[i];

	return ret;
}
