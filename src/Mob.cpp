#include <cstdlib>

#include "Mob.h"

// ---- PUBLIC ----

Mob::Mob(MobType type1, const sf::Texture &texture):
	type(type1),
	stats(0),
	behavior(NORMAL),
	path(0)
{
	sprite.setTexture(texture);
}

Mob::Mob()
{
    stats = 0;
}

Mob::~Mob()
{
	if(stats != 0)
		delete stats;

    if(path != 0)
	    delete path;
}

// #### DAMAGE METHODS ####

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

// #### LOOT METHODS ####

void Mob::LootMob(unsigned int lck)
{
    // Home-made algorithm for loot-%age
    unsigned int realDropRate = 0;
    std::vector<Item*> itemsToDrop;

    for(unsigned int i=0; i<loot.size(); ++i)
    {
        srand(time(NULL));
        realDropRate = loot[i]->dropRate + (int)((float)lck/(float)MAX_STAT)*MAX_ADD_DROP_RATE;
        realDropRate = (realDropRate > 100) ? 100 : realDropRate;

        if((unsigned int)(rand() % 100) > realDropRate)
        {
            itemsToDrop.push_back(loot[i]->item);
        }
    }
    if(itemsToDrop.size() > 0)
        dropItems(itemsToDrop);
}

// #### IA METHODS ####

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

// #### SETTERS ####

void Mob::SetPath(Path *path1)
{
	path = path1;
}

// #### GETTERS ####

Status Mob::GetStatus()
{
    return status;
}

Stats* Mob::GetStats()
{
    return stats;
}

unsigned int Mob::GiveXP()
{
    return xpDrop;
}

// ---- PUBLIC ----

// #### DAMAGE METHODS ####

unsigned int Mob::getPower()
{
    unsigned int power = 0;
    power = stats->GetAtt();
    return power;
}

unsigned int Mob::dealDamage(unsigned int power, Status ownStatus, unsigned int defense, Status enemyStatus)
{
    unsigned int damage = 0;
    damage = (power - defense/2)*(MAX_STAT - defense)/MAX_STAT;
    return damage;
}

// #### LOOT METHODS ####

void Mob::dropItems(std::vector<Item*> &itemsToDrop)
{
    // Drop items on the floor ?
    for(unsigned int i=0; i<itemsToDrop.size(); ++i)
    {
        // random offset between -X_SIZE_ITEM and +X_SIZE_ITEM
    }
}

