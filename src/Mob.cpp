#include "Mob.h"

Mob::Mob(MobType type1, const sf::Texture &texture):
	type(type1),
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
    power = stats->GetAtt();
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
    damage = (power - defense/2)*(MAX_STAT - defense)/MAX_STAT;
    return damage;
}

void Mob::SetPath(Path *path1)
{
	path = path1;
}

