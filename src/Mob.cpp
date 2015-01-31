#include "Mob.h"

Mob::Mob()
{
    //ctor
}

Mob::~Mob()
{
    delete stats;
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
