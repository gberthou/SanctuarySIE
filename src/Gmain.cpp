#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Resources.h"
#include "Map.h"
#include "Character.h"
#include "LevelBg.h"

int main(void)
{
	const int W = 800;
	const int H = 600;

	const float K = .25f;

	sf::Vector2i mouse;
	sf::Vector2f offset;

	sf::RenderWindow window(sf::VideoMode(W, H), "Sample");

	Map sanctuaryMap;
	LevelBg lbg;

	Resources::Load();

	sanctuaryMap.Load();

	lbg.SetLayer(0, "img/levels/sample/layer0.png");
	lbg.SetLayer(1, "img/levels/sample/layer1.png");
	lbg.SetLayer(2, "img/levels/sample/layer2.png");
	lbg.SetLayer(3, "img/levels/sample/layer3.png");

	sf::Mouse::setPosition(sf::Vector2i(W/2,H/2), window);

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		mouse = sf::Mouse::getPosition(window);
		offset.x = K * (W/2 - mouse.x);
		offset.y = K * (H/2 - mouse.y);
		lbg.SetOffset(offset);

		window.clear(sf::Color::Black);

		window.draw(lbg);

		window.display();
	}

	return 0;
}

