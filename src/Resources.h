#ifndef RESOURCES_H
#define RESOURCES_H

#include <SFML/Graphics.hpp>

class Resources
{
	public:
		static void Load(void);

		static sf::Texture texMap;
	
	private:
		Resources();
		virtual ~Resources();
};

#endif

