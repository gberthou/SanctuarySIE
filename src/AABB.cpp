#include "AABB.h"

AABB::AABB()
{
}

AABB::AABB(const sf::Vector2f &size1):
	size(size1)
{
}

AABB::~AABB()
{
}
	
bool AABB::CollidesWith(const AABB &box) const
{
	return box.pos.x < pos.x + size.x
		&& box.pos.x + box.size.x > pos.x
		&& box.pos.y < pos.y + size.y
		&& box.pos.y + box.size.y > pos.y;
}

void AABB::SetPosition(const sf::Vector2f &position)
{
	pos = position;
}

void AABB::SetSize(const sf::Vector2f &size1)
{
	size = size1;
}

