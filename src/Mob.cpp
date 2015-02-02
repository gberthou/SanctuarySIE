#include "Mob.h"

Mob::Mob(MobType type1, const sf::Texture &texture):
	type(type1),
	behavior(NORMAL),
	path(0)
{
	sprite.setTexture(texture);
}

Mob::Mob()
{

}

Mob::~Mob()
{
    delete stats;

    if(path != 0)
	    delete path;
}

Status Mob::GetStatus()
{
    return status;
}

Stats* Mob::GetStats()
{
    return stats;
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

void Mob::Drop(unsigned int lck)
{

}

unsigned int Mob::GiveXP()
{
    return xpDrop;
}

void Mob::SetPath(Path *path1)
{
	path = path1;
}

void Mob::UpdateAI(void)
{
	const float EPSILON = 1; // Warning : may be capricious if the initial mob position is not adapted to the
							 // collision map (ie. if the mob is a few pixels above the local floor)
	
	if(behavior == NORMAL)
	{
		sf::Vector2f objective = path->GetNextPosition();
		sf::Vector2f diff = objective - pos;

		if(diff.x * diff.x + diff.y * diff.y < EPSILON)
		{
			path->PositionReached();
		}
		else if(diff.x > 0) // Objective is on the right
		{
			pos.x += 1;
		}
		else
		{
			pos.x -= 1;
		}
	}
}

