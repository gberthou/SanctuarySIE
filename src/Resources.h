#ifndef RESOURCES_H
#define RESOURCES_H

#include <SFML/Graphics.hpp>

class Resources
{
	public:
		static void Load(void);

		// Map
		static sf::Texture texMap;
		
		// Characters
		static sf::Texture texCharacter;

		// Mobs
		static sf::Texture texGiantBat;

	private:
		Resources();
		virtual ~Resources();
};

#endif

