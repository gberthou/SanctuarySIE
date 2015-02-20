#include "LevelDoor.h"

LevelDoor::LevelDoor(IdLevel idLevel1, const AABB &hitbox1, unsigned int lx1, unsigned int ly1, DoorDirection dir):
	idLevel(idLevel1),
	target(0),
	hitbox(hitbox1),
	lx(lx1),
	ly(ly1),
	direction(dir)
{
}

LevelDoor::~LevelDoor()
{
}

void LevelDoor::SetTarget(const LevelDoor *target1)
{
	target = target1;
}

bool LevelDoor::CollidesWith(const Entity *entity) const
{
	return hitbox.CollidesWith(entity->GetHitbox());
}

IdLevel LevelDoor::GetIdLevel(void) const
{
	return idLevel;
}

const LevelDoor *LevelDoor::GetTarget(void) const
{
	return target;
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

