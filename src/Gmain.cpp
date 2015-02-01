#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Resources.h"
#include "Map.h"
#include "Character.h"
#include "LevelBg.h"
#include "MobFactory.h"
#include "LevelFactory.h"

int main(void)
{
	const unsigned int W = 800;
	const unsigned int H = 600;

	sf::RenderWindow window(sf::VideoMode(W, H), "Sample");

	Level *level = LevelFactory::CreateLevel(CORRIDOR0);
	
	Resources::Load();

	// Simulate the arrival of the player in the level
	level->MakeReady();

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		window.draw(*level);

		window.display();
	}

	return 0;
}

