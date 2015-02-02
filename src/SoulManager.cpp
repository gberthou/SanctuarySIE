#include "SoulManager.h"
#include "RedSoul.h"
#include "BlueSoul.h"
#include "YellowSoul.h"

SoulManager::SoulManager()
{
    souls[GIANT_BAT] = new RedSoul();
}

SoulManager::~SoulManager()
{
    // dtor
}

Soul *SoulManager::GetSoul(MobType type)
{
    if (type<0 || type >= MOB_COUNT)
    {
        return (Soul*)0;
    }
    return souls[type];
}
