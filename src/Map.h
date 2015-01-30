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
	
		void Load(void);

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	private:
		
		// data
		std::vector<Level*> levels;
};

#endif

