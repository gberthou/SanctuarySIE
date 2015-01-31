#include "Mob.h"

Mob::Mob(const sf::Texture &texture):
	path(0)
{
	sprite.setTexture(texture);
}

Mob::~Mob()
{
    delete stats;

    if(path != 0)
	    delete path;
}

unsigned int Mob::getPower()
{
    unsigned int power = 0;
    return power;
}

bool Mob::Hurt(unsigned int damage)
{
    if(hp - damage <= 0)
    {
        hp = 0;
        return true;
    }
    else
    {
        hp -= damage;
        return false;
    }
}

unsigned int Mob::DealDamage(unsigned int power, Status ownStatus, unsigned int defense, Status enemyStatus)
{
    unsigned int damage = 0;
    return damage;
}

void Mob::SetPath(Path *path1)
{
	path = path1;
}

