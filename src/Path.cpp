#include "Path.h"

Path::Path()
{
}

Path::~Path()
{
}

void Path::AddPosition(const sf::Vector2f &position)
{
	positions.push_back(position);
}

void Path::MakeReady(void)
{
	next = positions.begin();
}

sf::Vector2f Path::GetNextPosition(void) const
{
	return *next;
}

void Path::PositionReached(void)
{
	next++;
	if(next == positions.end())
			next = positions.begin();
}

