#include "LevelDoor.h"

LevelDoor::LevelDoor(IdLevel target1, const AABB &hitbox1, unsigned int lx1, unsigned int ly1, DoorDirection dir):
	target(target1),
	hitbox(hitbox1),
	lx(lx1),
	ly(ly1),
	direction(dir)
{
}

LevelDoor::~LevelDoor()
{
}

bool LevelDoor::CollidesWith(const Entity *entity) const
{
	return hitbox.CollidesWith(entity->GetHitbox());
}

const AABB &LevelDoor::GetHitbox(void) const
{
	return hitbox;
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

