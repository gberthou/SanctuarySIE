#include "Path.h"

Path::Path()
{
}

Path::~Path()
{
}

void Path::AddPosition(sf::Vector2f position)
{
	positions.push_back(position);
}

void Path::Ready(void)
{
	next = positions.begin();
}

sf::Vector2f Path::GetNextPosition(void) const
{
	return *next;
}

