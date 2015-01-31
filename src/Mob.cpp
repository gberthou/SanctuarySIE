#include "Mob.h"

Mob::Mob():
	path(0)
{
}

Mob::~Mob()
{
    delete stats;

    if(path != 0)
	    delete path;
}

void Mob::SetPath(Path *path1)
{
	path = path1;
}

