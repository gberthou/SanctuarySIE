#ifndef RESOURCES_H
#define RESOURCES_H

#include <SFML/Graphics.hpp>

class Resources
{
	public:
		static bool Load(void);

		// Map
		static sf::Texture texMap;
		
		// Characters
		static sf::Texture texCharacter;

		// Mobs
		static sf::Texture texGiantBat;

		// Items
		static sf::Texture texDagger;

		// Souls
		static sf::Texture texRedSoul;

	private:
		Resources();
		virtual ~Resources();
};

#endif

