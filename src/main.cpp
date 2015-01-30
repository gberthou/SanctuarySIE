#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Resources.h"
#include "Map.h"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Sample");

	Map map;

	Resources::Load();

	map.Load();

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);
		
		window.draw(map);
		
		window.display();
	}

	return 0;
}

