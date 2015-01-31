#ifndef MAP_H
#define MAP_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "Level.h"

struct LevelConnection
{
	LevelConnection(Level *l1, Level *l2):
		level1(l1),
		level2(l2)
	{
	}

	Level *level1;
	Level *level2;
};

class Map : public sf::Drawable
{
	public:
		Map();
		virtual ~Map();
	
		void Load(void);

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	private:
		void drawDoors(sf::RenderTarget &target, sf::RenderStates states) const;

		std::vector<Level*> levels;
		std::vector<LevelConnection*> connections;
};

#endif

