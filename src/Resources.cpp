#include <SFML/System.hpp>

#include "Resources.h"

const sf::String strMap("img/map.png");

sf::Texture Resources::texMap;

void Resources::Load(void)
{
	texMap.loadFromFile(strMap);
}

