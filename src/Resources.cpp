#include <SFML/System.hpp>

#include "Resources.h"

const sf::String strMap("img/map.png");
const sf::String strCharacter("img/character.png");

sf::Texture Resources::texMap;
sf::Texture Resources::texCharacter;

void Resources::Load(void)
{
	texMap.loadFromFile(strMap);
	texCharacter.loadFromFile(strCharacter);
}

