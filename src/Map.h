#ifndef MAP_H
#define MAP_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "Level.h"

class Map : public sf::Drawable
{
	public:
		Map();
		virtual ~Map();
	
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states);
	private:
		void load(void);
		
		std::vector<Level*> levels;
};

#endif

