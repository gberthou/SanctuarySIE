#include "Entity.h"

void Entity::Update()
{
    a = forces/mass;
    v += a*DT;
    pos += v*DT;
}
