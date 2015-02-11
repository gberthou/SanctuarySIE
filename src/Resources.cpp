#include <SFML/System.hpp>

#include "Resources.h"

const sf::String S_MAP("img/map.png");
const sf::String S_CHARACTER("img/character.png");
const sf::String S_GIANTBAT("img/mobs/giantBat.png");
const sf::String S_DAGGER("img/items/dagger.png");
const sf::String S_REDSOUL("img/redsoul.png");


sf::Texture Resources::texMap;
sf::Texture Resources::texCharacter;
sf::Texture Resources::texGiantBat;
sf::Texture Resources::texDagger;
sf::Texture Resources::texRedSoul;

void Resources::Load(void)
{
	// Map
	texMap.loadFromFile(S_MAP);
	
	// Character
	texCharacter.loadFromFile(S_CHARACTER);

	// Mobs
	texGiantBat.loadFromFile(S_GIANTBAT);

	// Items
	texDagger.loadFromFile(S_DAGGER);

	// Souls
	texRedSoul.loadFromFile(S_REDSOUL);
}

