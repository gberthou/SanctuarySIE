#include <vector>

#include "InputController.h"
#include "MenuTitle1.h"
#include "SerGUI.h"
#include "Bat.h"
#include "FPSClock.h"

static const char* S_VERT_SHADER("shaders/base.vert");
static const char* S_FRAG_SHADER("shaders/SerGUI1.frag");
static const char* S_BACKGROUND("img/sergui/title1.png");
static const char* S_COVER("img/sergui/title1cover.png");
static const char* S_BAT("img/sergui/bat.png");
static const char* S_TEXT = "img/sergui/title_press_enter.png";

const unsigned int NBATS = 333;

MenuTitle1::MenuTitle1()
{
}

bool MenuTitle1::Load(void)
{
	return shader.loadFromFile(S_VERT_SHADER, S_FRAG_SHADER)
		&& texBackground.loadFromFile(S_BACKGROUND)
		&& texCover.loadFromFile(S_COVER)
		&& texBat.loadFromFile(S_BAT)
		&& texText.loadFromFile(S_TEXT);
}

MenuTitle1Code MenuTitle1::Run(void)
{
        text.setTexture(texText);
    text.setOrigin(text.getGlobalBounds().width/2.f,
                   text.getGlobalBounds().height*1.0f);
    text.setPosition(SerGUI::window.getSize().x/2.f,SerGUI::window.getSize().y-0.f);
    shader.setParameter("texture", sf::Shader::CurrentTexture);

	MenuTitle1Code ret = EXIT;

	sf::Sprite background(texBackground);
	sf::Sprite cover(texCover);

	std::vector<Bat*> inside(NBATS);
	std::vector<Bat*> outside;

	sf::Clock timer;
	FPSClock clock(60);
	
	for(unsigned int i = 0; i < NBATS; ++i)
	{
		inside[i] = new Bat(texBat);
	}

	clock.restart();

    while(SerGUI::window.isOpen() && ret == EXIT)
	{
		sf::Event event;
		unsigned int nframes;
		
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
		
		nframes = clock.GetElapsedFrames();
		if(nframes > 0) // Important
			clock.restart();

		// Make the bats pass from the inside collection to the outside collection
		for(std::vector<Bat*>::iterator it = inside.begin(); it != inside.end();)
		{
			(*it)->Update(nframes);
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
			outside[i]->Update(nframes);

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

        // the bottom text
		shader.setParameter("time", timer.getElapsedTime().asSeconds());
		SerGUI::window.draw(text,&shader);

		SerGUI::window.display();
	}

	for(unsigned int i = 0; i < inside.size(); ++i)
		delete inside[i];

	for(unsigned int i = 0; i < outside.size(); ++i)
		delete outside[i];

	return ret;
}

