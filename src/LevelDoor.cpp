#include "LevelDoor.h"

LevelDoor::LevelDoor(IdLevel target1, unsigned int lx1, unsigned int ly1, DoorDirection dir):
	target(target1),
	lx(lx1),
	ly(ly1),
	direction(dir)
{
}

LevelDoor::~LevelDoor()
{
}

unsigned int LevelDoor::GetLocalX(void) const
{
	return lx;
}

unsigned int LevelDoor::GetLocalY(void) const
{
	return ly;
}

DoorDirection LevelDoor::GetDirection(void) const
{
	return direction;
}

