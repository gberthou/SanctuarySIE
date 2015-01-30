#include "Resources.h"
#include "Map.h"

const unsigned int BLOCK_SIZE = 32;

Map::Map()
{
}

Map::~Map()
{
}

void Map::Load(void)
{
	for(unsigned int i = 0; i < levels.size(); ++i)
		delete levels[i];
	levels.clear();

	// Hard-coded
	levels.push_back(new Level(10,10,1,1));
	levels.push_back(new Level(11,10,1,1));
	levels.push_back(new Level(11,11,1,1));
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	sf::Sprite smallRoom(Resources::texMap, sf::IntRect(0,0,BLOCK_SIZE,BLOCK_SIZE));
	for(unsigned int i = 0; i < levels.size(); ++i)
	{
		Level *level = levels[i];
		unsigned int w = level->GetWidth();
		unsigned int h = level->GetHeight();

		if(w == 1 && h == 1) // Small room
		{
			smallRoom.setPosition(level->GetX() * BLOCK_SIZE, level->GetY() * BLOCK_SIZE);
			target.draw(smallRoom);
		}
		else
		{
		}
	}
}

