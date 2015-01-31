#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Resources.h"
#include "Map.h"
#include "Character.h"
#include "LevelBg.h"

#define GAUTIER

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Sample");

	Map sanctuaryMap;
	LevelBg lbg;

	Resources::Load();

	Character* chara = new Character();

	sanctuaryMap.Load();

	lbg.SetLayer(0, "img/levels/sample/layer0.png");
	lbg.SetLayer(1, "img/levels/sample/layer1.png");
	lbg.SetLayer(2, "img/levels/sample/layer2.png");
	lbg.SetLayer(3, "img/levels/sample/layer3.png");

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

#ifdef GAUTIER
		window.draw(lbg);		
#endif

		window.display();
	}

	return 0;
}

