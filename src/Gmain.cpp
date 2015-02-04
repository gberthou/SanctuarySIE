#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Resources.h"
#include "Map.h"
#include "Character.h"
#include "LevelBg.h"
#include "MobFactory.h"
#include "LevelFactory.h"
#include "FPSClock.h"
#include "InputController.h"

int main(void)
{
	const unsigned int W = 800;
	const unsigned int H = 600;

	sf::RenderWindow window(sf::VideoMode(W, H), "Sample");
	FPSClock clock(60);
	Level *level;
	Character *character;
	InputController *inputController;

	Resources::Load();

	level = LevelFactory::CreateLevel(CORRIDOR0);
	character = new Character();

    inputController = new InputController(character);


	// Simulate the arrival of the player in the level
	level->MakeReady(character);

	while(window.isOpen())
	{
		unsigned int frameCount;
		sf::Event event;

		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();

			inputController->Update(event);
		}

		frameCount = clock.GetElapsedFrames();
		if(frameCount > 0)
			clock.restart();

		window.clear(sf::Color::Black);

		window.draw(*level);

		window.display();

		level->Update(frameCount);
	}

	delete level;
	delete character;
	delete inputController;

	return 0;
}

