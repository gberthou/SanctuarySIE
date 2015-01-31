#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Resources.h"
#include "Map.h"
#include "Character.h"
#include "LevelBg.h"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Sample");

	Map sanctuaryMap;

	Resources::Load();

	Character* chara = new Character();

	sanctuaryMap.Load();
	Physics physics;
	physics.AddEntity(chara);

    sf::Image bitmap;
	bitmap.loadFromFile("img/bitmap.png");

	sf::Sprite spriteBitmap;
	sf::Texture texmap;
	texmap.loadFromImage(bitmap);
	spriteBitmap.setTexture(texmap);

	physics.AddCollisionMap(&bitmap);


	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		physics.Update();


		window.clear(sf::Color::Black);
        window.draw(spriteBitmap);
		//window.draw(sanctuaryMap);
		window.draw(*chara);

		window.display();
	}

	return 0;
}

