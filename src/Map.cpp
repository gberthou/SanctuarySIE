#include <iostream>

#include "Resources.h"
#include "Map.h"

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
}

void Map::Load(void)
{
	for(unsigned int i = 0; i < levels.size(); ++i)
		delete levels[i];
	levels.clear();

	// Hard-coded
	levels.push_back(new Level(10,10,1,1));
	levels.push_back(new Level(11,10,1,1));
	levels.push_back(new Level(10,11,4,5));

	connections.push_back(new LevelConnection(levels[1],levels[0]));
	connections.push_back(new LevelConnection(levels[1],levels[2]));
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	sf::Sprite smallRoom(Resources::texMap, sf::IntRect(0,0,BLOCK_SIZE,BLOCK_SIZE));
	
	sf::Sprite tlCorner(Resources::texMap, sf::IntRect(BLOCK_SIZE,0,BLOCK_SIZE,BLOCK_SIZE));              // Top-left
	sf::Sprite trCorner(Resources::texMap, sf::IntRect(BLOCK_SIZE*3,0,BLOCK_SIZE,BLOCK_SIZE));            // Top-right
	sf::Sprite blCorner(Resources::texMap, sf::IntRect(BLOCK_SIZE,BLOCK_SIZE*2,BLOCK_SIZE,BLOCK_SIZE));   // Bottom-left
	sf::Sprite brCorner(Resources::texMap, sf::IntRect(BLOCK_SIZE*3,BLOCK_SIZE*2,BLOCK_SIZE,BLOCK_SIZE)); // Bottom-right

	sf::Sprite tEdge(Resources::texMap, sf::IntRect(BLOCK_SIZE*2,0,BLOCK_SIZE,BLOCK_SIZE));            // Top
	sf::Sprite rEdge(Resources::texMap, sf::IntRect(BLOCK_SIZE*3,BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE));   // Right
	sf::Sprite bEdge(Resources::texMap, sf::IntRect(BLOCK_SIZE*2,BLOCK_SIZE*2,BLOCK_SIZE,BLOCK_SIZE)); // Bottom
	sf::Sprite lEdge(Resources::texMap, sf::IntRect(BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE));     // Left
	
	sf::Sprite center(Resources::texMap, sf::IntRect(BLOCK_SIZE*2,BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE)); // Center

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
		}
		else if(h == 1) // Horizontal room
		{
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
	}

	drawDoors(target, states);
}

void Map::drawDoors(sf::RenderTarget &target, sf::RenderStates states) const
{
	// The following constants define the 4 neighbours (left, up, down, right)
	const int DX[4] = {-1, 0, 0, 1};
	const int DY[4] = {0, -1, 1, 0};

	sf::Sprite verticalDoor(Resources::texMap, sf::IntRect(0,BLOCK_SIZE,VDOOR_WIDTH,VDOOR_HEIGHT));
	sf::Sprite horizontalDoor(Resources::texMap, sf::IntRect(0,2*BLOCK_SIZE-HDOOR_HEIGHT,HDOOR_WIDTH,HDOOR_HEIGHT));

	for(unsigned int i = 0; i < connections.size(); ++i)
	{
		bool done = false;
		Level *level1 = connections[i]->level1;
		Level *level2 = connections[i]->level2;

		// For each block unit in level1
		for(unsigned int x = 0; x < level1->GetWidth() && !done; ++x)
			for(unsigned int y = 0; y < level1->GetHeight() && !done; ++y)
			{
				// Test all neighbours
				for(unsigned int j = 0; j < 4; ++j) 
				{
					int tmpX = level1->GetX() + x + DX[j];
					int tmpY = level1->GetY() + y + DY[j];

					int x2 = level2->GetX();
					int y2 = level2->GetY();

					// If the neighbour is inside the second level
					if(tmpX >= x2 && tmpX < x2 + (int) level2->GetWidth()
				        && tmpY >= y2 && tmpY < y2 + (int) level2->GetHeight())
					{
						// Test the side of the connection
						switch(j)
						{
							case 1: // Up
								// Draw the door upwards
								horizontalDoor.setPosition(tmpX * BLOCK_SIZE, (tmpY+1) * BLOCK_SIZE - HDOOR_HEIGHT);
								target.draw(horizontalDoor, states);
							
								// Draw the door downwards	
								horizontalDoor.setPosition(tmpX * BLOCK_SIZE, (tmpY+1) * BLOCK_SIZE);
								target.draw(horizontalDoor, states);
								
								break;

							case 2: // Down
								// Draw the door upwards
								horizontalDoor.setPosition(tmpX * BLOCK_SIZE, tmpY * BLOCK_SIZE - HDOOR_HEIGHT);
								target.draw(horizontalDoor, states);
								
								//Draw the door downwards
								horizontalDoor.setPosition(tmpX * BLOCK_SIZE, tmpY * BLOCK_SIZE);
								target.draw(horizontalDoor, states);
								break;

							case 3: // Right
								// Draw the door on the right
								verticalDoor.setPosition(tmpX * BLOCK_SIZE, tmpY * BLOCK_SIZE);
								target.draw(verticalDoor, states);

								// Draw the door on the left
								verticalDoor.setPosition(tmpX * BLOCK_SIZE - VDOOR_WIDTH, tmpY * BLOCK_SIZE);
								target.draw(verticalDoor, states);
								break;

							default: // Left
								// Draw the door on the right
								verticalDoor.setPosition((tmpX+1) * BLOCK_SIZE, tmpY * BLOCK_SIZE);
								target.draw(verticalDoor, states);

								// Draw the door on the left
								verticalDoor.setPosition((tmpX+1) * BLOCK_SIZE - VDOOR_WIDTH, tmpY * BLOCK_SIZE);
								target.draw(verticalDoor, states);
								break;
						}
						done = true;
					}
				}
			}
	}
}

