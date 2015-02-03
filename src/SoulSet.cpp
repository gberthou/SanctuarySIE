#include "SoulSet.h"
#include "SoulManager.h"
#include "RedSoul.h"
#include "BlueSoul.h"
#include "YellowSoul.h"

SoulSet::SoulSet() :
    redSoul((RedSoul*)0),
    blueSoul((BlueSoul*)0),
    yellowSoul((YellowSoul*)0),
    soulManager(new SoulManager())
{
    // ctor
}

SoulSet::~SoulSet()
{
    delete redSoul;
    delete blueSoul;
    delete yellowSoul;
}

RedSoul *SoulSet::GetRedSoul()
{
    return redSoul;
}

BlueSoul *SoulSet::GetBlueSoul()
{
    return blueSoul;
}

YellowSoul *SoulSet::GetYellowSoul()
{
    return yellowSoul;
}

