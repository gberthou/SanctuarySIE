#include "Fighter.h"

#define DEBUG_FIGHTER_HURT

Fighter::Fighter(Stats *stats, unsigned int maxHP1, unsigned int maxMP1):
	hp(maxHP1),
	mp(maxMP1),
	maxHP(maxHP1),
	maxMP(maxMP1),
	baseStats(stats)
{
}

Fighter::~Fighter()
{
	delete baseStats;
}

void Fighter::UpdateBehavior()
{
	if(hp != 0) // Still alive
		updateFighter();
	else        // Dead actually
	{
	}
}

bool Fighter::Hurt(unsigned int damage)
{
#ifdef DEBUG_FIGHTER_HURT
	std::cout << "Fighter takes " << damage << " damage" << std::endl;
#endif

    if(hp <= damage)
    {
        hp = 0;
#ifdef DEBUG_FIGHTER_HURT
	std::cout << "Fighter dead" << std::endl;
	std::cout << std::endl;
#endif
        return true;
    }

	hp -= damage;
#ifdef DEBUG_FIGHTER_HURT
	std::cout << "Fighter hp left: " << hp << std::endl;
	std::cout << std::endl;
#endif
	return false;
}

bool Fighter::IsDead() const
{
	return hp == 0;
}

Status Fighter::GetStatus() const
{
	return status;
}

const Stats *Fighter::GetEffectiveStats() const
{
	return baseStats;
}

