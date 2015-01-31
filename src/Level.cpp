#include "Level.h"

Level::Level(unsigned int x1, unsigned int y1, unsigned int width1, unsigned int height1):
	x(x1),
	y(y1),
	width(width1),
	height(height1)
{
}

Level::~Level()
{
	for(unsigned int i = 0; i < doors.size(); ++i)
		delete doors[i];
}

void Level::AddDoor(Level *target, unsigned int lx, unsigned int ly, DoorDirection direction)
{
	doors.push_back(new LevelDoor(target, lx, ly, direction));
}

unsigned int Level::GetX(void) const
{
	return x;
}

unsigned int Level::GetY(void) const
{
	return y;
}
		
unsigned int Level::GetWidth(void) const
{
	return width;
}

unsigned int Level::GetHeight(void) const
{
	return height;
}

const std::vector<LevelDoor*> &Level::GetDoors(void) const
{
	return doors;
}

