#include "SoulManager.h"
#include "RedSoul.h"
#include "BlueSoul.h"
#include "YellowSoul.h"

SoulManager::SoulManager()
{
    int i;
    for (i=0; i<MOB_COUNT; i++)
    {
        souls[i] = (Soul*)0;
    }
    souls[GIANT_BAT] = new RedSoul();
}

SoulManager::~SoulManager()
{
    delete souls[GIANT_BAT];
}

Soul *SoulManager::GetSoul(MobType type)
{
    if (type<0 || type >= MOB_COUNT)
    {
        return (Soul*)0;
    }
    return souls[type];
}
