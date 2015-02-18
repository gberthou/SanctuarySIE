#include "AABB.h"

AABB::AABB()
{
}

AABB::AABB(const sf::Vector2f &size1):
	size(size1)
{
}

AABB::AABB(const sf::Vector2f &position, const sf::Vector2f &size1):
	pos(position),
	size(size1)
{
}

AABB::AABB(const AABB &other):
	pos(other.pos),
	size(other.size)
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

bool AABB::CollidesWith(const sf::Vector2f &point) const
{
	return point.x >= pos.x
		&& point.x <= pos.x + size.x
		&& point.y >= pos.y
		&& point.y <= pos.y + size.y;
}

void AABB::SetPosition(const sf::Vector2f &position)
{
	pos = position;
}

void AABB::SetSize(const sf::Vector2f &size1)
{
	size = size1;
}

sf::Vector2f AABB::GetPosition(void) const
{
	return pos;
}

sf::Vector2f AABB::GetSize(void) const
{
	return size;
}

