#include "Mob.h"

Mob::Mob(MobType type1, const sf::Texture &texture):
	type(type1),
	behavior(NORMAL),
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

void Mob::UpdateAI(void)
{
	const float EPSILON = 1;
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

	sprite.setPosition(pos);
}

