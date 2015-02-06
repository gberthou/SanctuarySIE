#include "SoulManager.h"
#include "RedSoul.h"
#include "BlueSoul.h"
#include "YellowSoul.h"

SoulManager::SoulManager()
{
    for (unsigned i=0; i<MOB_COUNT; ++i)
    {
        souls[i] = (Soul*)0;
    }

    souls[GIANT_BAT] = new RedSoul(GIANT_BAT, 800);
	souls[DEVIL] = new BlueSoul(DEVIL, BSOUL_B_HOLD);
}

SoulManager::~SoulManager()
{
	for(unsigned int i = 0; i < MOB_COUNT; ++i)
		if(souls[i] != 0)
			delete souls[i];
}

Soul *SoulManager::GetSoul(MobType type)
{
    if (type<0 || type >= MOB_COUNT)
    {
        return (Soul*)0;
    }
    return souls[type];
}
