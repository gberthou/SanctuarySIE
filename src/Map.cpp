#include <iostream>

#include "Resources.h"
#include "Map.h"
#include "LevelFactory.h"
#include "LevelDoor.h"

const unsigned int BLOCK_SIZE = 32;

const unsigned int HDOOR_WIDTH = BLOCK_SIZE;
const unsigned int HDOOR_HEIGHT = 2;

const unsigned int VDOOR_WIDTH = 2;
const unsigned int VDOOR_HEIGHT = BLOCK_SIZE;

Map::Map()
{
}

Map::~Map()
{
	for(unsigned int i = 0; i < levels.size(); ++i)
		delete levels[i];
}

void Map::Load(void)
{
	for(unsigned int i = 0; i < levels.size(); ++i)
		delete levels[i];
	levels.clear();

	for(unsigned int i = 0; i < LEVEL_NUMBER; ++i)
		levels.push_back(LevelFactory::CreateLevel((IdLevel)i));

	/*
	// Hard-coded
	levels.push_back(new Level(10,9,1,2));
	levels.push_back(new Level(11,10,4,1));
	levels.push_back(new Level(10,11,4,5));
	levels.push_back(new Level(9,14,1,1));

	levels[0]->AddDoor(levels[1], 0, 1, RIGHT);
	levels[1]->AddDoor(levels[0], 0, 0, LEFT);

	levels[1]->AddDoor(levels[2], 2, 0, DOWN);
	levels[2]->AddDoor(levels[1], 3, 0, UP);

	levels[2]->AddDoor(levels[3], 0, 3, LEFT);
	levels[3]->AddDoor(levels[2], 0, 0, RIGHT);
	*/
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	// 1x1
	sf::Sprite smallRoom(Resources::texMap, sf::IntRect(0,0,BLOCK_SIZE,BLOCK_SIZE));
	
	// Dimensions > 1
	sf::Sprite tlCorner(Resources::texMap, sf::IntRect(BLOCK_SIZE,0,BLOCK_SIZE,BLOCK_SIZE));              // Top-left
	sf::Sprite trCorner(Resources::texMap, sf::IntRect(BLOCK_SIZE*3,0,BLOCK_SIZE,BLOCK_SIZE));            // Top-right
	sf::Sprite blCorner(Resources::texMap, sf::IntRect(BLOCK_SIZE,BLOCK_SIZE*2,BLOCK_SIZE,BLOCK_SIZE));   // Bottom-left
	sf::Sprite brCorner(Resources::texMap, sf::IntRect(BLOCK_SIZE*3,BLOCK_SIZE*2,BLOCK_SIZE,BLOCK_SIZE)); // Bottom-right

	sf::Sprite tEdge(Resources::texMap, sf::IntRect(BLOCK_SIZE*2,0,BLOCK_SIZE,BLOCK_SIZE));            // Top
	sf::Sprite rEdge(Resources::texMap, sf::IntRect(BLOCK_SIZE*3,BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE));   // Right
	sf::Sprite bEdge(Resources::texMap, sf::IntRect(BLOCK_SIZE*2,BLOCK_SIZE*2,BLOCK_SIZE,BLOCK_SIZE)); // Bottom
	sf::Sprite lEdge(Resources::texMap, sf::IntRect(BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE));     // Left
	
	sf::Sprite center(Resources::texMap, sf::IntRect(BLOCK_SIZE*2,BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE));  // Center

	// Width = 1
	sf::Sprite t1X(Resources::texMap, sf::IntRect(BLOCK_SIZE*4,0,BLOCK_SIZE,BLOCK_SIZE));
	sf::Sprite c1X(Resources::texMap, sf::IntRect(BLOCK_SIZE*4,BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE));
	sf::Sprite b1X(Resources::texMap, sf::IntRect(BLOCK_SIZE*4,BLOCK_SIZE*2,BLOCK_SIZE,BLOCK_SIZE));

	// Height = 1
	sf::Sprite tX1(Resources::texMap, sf::IntRect(BLOCK_SIZE*5,0,BLOCK_SIZE,BLOCK_SIZE));
	sf::Sprite cX1(Resources::texMap, sf::IntRect(BLOCK_SIZE*6,0,BLOCK_SIZE,BLOCK_SIZE));
	sf::Sprite bX1(Resources::texMap, sf::IntRect(BLOCK_SIZE*7,0,BLOCK_SIZE,BLOCK_SIZE));

	for(unsigned int i = 0; i < levels.size(); ++i)
	{
		Level *level = levels[i];
		unsigned int x = level->GetX();
		unsigned int y = level->GetY();
		unsigned int w = level->GetWidth();
		unsigned int h = level->GetHeight();

		if(w == 1 && h == 1) // Small room
		{
			smallRoom.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
			target.draw(smallRoom, states);
		}
		else if(w == 1) // Vertical room
		{
			t1X.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
			b1X.setPosition(x * BLOCK_SIZE, (y + h - 1) * BLOCK_SIZE);
			target.draw(t1X, states);
			target.draw(b1X, states);

			for(unsigned int i = 1; i < h - 1; ++i)
			{
				c1X.setPosition(x * BLOCK_SIZE, (y + i) * BLOCK_SIZE);
				target.draw(c1X, states);
			}
		}
		else if(h == 1) // Horizontal room
		{
			tX1.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
			bX1.setPosition((x + w - 1) * BLOCK_SIZE, y * BLOCK_SIZE);
			target.draw(tX1, states);
			target.draw(bX1, states);

			for(unsigned int i = 1; i < w - 1; ++i)
			{
				cX1.setPosition((x + i) * BLOCK_SIZE, y * BLOCK_SIZE);
				target.draw(cX1, states);
			}
		}
		else
		{
			// Set corners
			tlCorner.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
			trCorner.setPosition((x + w - 1) * BLOCK_SIZE, y * BLOCK_SIZE);
			blCorner.setPosition(x * BLOCK_SIZE, (y + h - 1) * BLOCK_SIZE);
			brCorner.setPosition((x + w - 1) * BLOCK_SIZE, (y + h - 1) * BLOCK_SIZE);
			target.draw(tlCorner, states);
			target.draw(trCorner, states);
			target.draw(blCorner, states);
			target.draw(brCorner, states);

			// Top & Bottom lines
			for(unsigned int i = 1; i < w - 1; ++i)
			{
				tEdge.setPosition((x + i) * BLOCK_SIZE, y * BLOCK_SIZE);
				bEdge.setPosition((x + i) * BLOCK_SIZE, (y + h - 1) * BLOCK_SIZE);
				target.draw(tEdge, states);
				target.draw(bEdge, states);
			}

			// Left & Right lines
			for(unsigned int i = 1; i < h - 1; ++i)
			{
				lEdge.setPosition(x * BLOCK_SIZE, (y + i) * BLOCK_SIZE);
				rEdge.setPosition((x + w - 1) * BLOCK_SIZE, (y + i) * BLOCK_SIZE);
				target.draw(lEdge, states);
				target.draw(rEdge, states);
			}

			// Center
			for(unsigned int i = 1; i < w - 1; ++i)
				for(unsigned int j = 1; j < h - 1; ++j)
				{
					center.setPosition((x + i) * BLOCK_SIZE, (y + j) * BLOCK_SIZE);
					target.draw(center, states);
				}
		}
		
		drawLevelDoors(level, target, states);
	}
}

void Map::drawLevelDoors(Level *level, sf::RenderTarget &target, sf::RenderStates states) const
{
	const std::vector<LevelDoor*> &doors = level->GetDoors();
	unsigned int x = level->GetX();
	unsigned int y = level->GetY();

	sf::Sprite verticalDoor(Resources::texMap, sf::IntRect(0,BLOCK_SIZE,VDOOR_WIDTH,VDOOR_HEIGHT));
	sf::Sprite horizontalDoor(Resources::texMap, sf::IntRect(0,2*BLOCK_SIZE-HDOOR_HEIGHT,HDOOR_WIDTH,HDOOR_HEIGHT));
	
	for(unsigned int i = 0; i < doors.size(); ++i)
	{
		switch(doors[i]->GetDirection())
		{
			case UP:
				horizontalDoor.setPosition((x+doors[i]->GetLocalX()) * BLOCK_SIZE, (y+doors[i]->GetLocalY()) * BLOCK_SIZE);
				target.draw(horizontalDoor, states);
				break;

			case DOWN:
				horizontalDoor.setPosition((x+doors[i]->GetLocalX()) * BLOCK_SIZE, (y+doors[i]->GetLocalY()+1) * BLOCK_SIZE - HDOOR_HEIGHT);
				target.draw(horizontalDoor, states);
				break;

			case RIGHT:
				verticalDoor.setPosition((x+doors[i]->GetLocalX()+1) * BLOCK_SIZE - VDOOR_WIDTH, (y+doors[i]->GetLocalY()) * BLOCK_SIZE);
				target.draw(verticalDoor, states);
				break;

			default: // LEFT
				verticalDoor.setPosition((x+doors[i]->GetLocalX()) * BLOCK_SIZE, (y+doors[i]->GetLocalY()) * BLOCK_SIZE);
				target.draw(verticalDoor, states);
				break;
		}
	}
}

