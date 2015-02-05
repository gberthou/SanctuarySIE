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
}

SoulSet::~SoulSet()
{
	delete soulManager;
}

void SoulSet::AddSoul(MobType type)
{
	Soul *soul = soulManager->GetSoul(type);

	switch(soul->GetSoulType())
	{
		case SOULTYPE_RED:
			addRedSoul((RedSoul*) soul);
			break;
		default:
			break;
	}
}

void SoulSet::EquipRedSoul(std::vector<RedSoul*>::const_iterator it)
{
	redSoul = *it;
}

RedSoul *SoulSet::GetRedSoul() const
{
    return redSoul;
}

const std::vector<RedSoul*> &SoulSet::GetRedSouls() const
{
	return redSouls;
}

BlueSoul *SoulSet::GetBlueSoul() const
{
    return blueSoul;
}

YellowSoul *SoulSet::GetYellowSoul() const
{
    return yellowSoul;
}

void SoulSet::addRedSoul(RedSoul *soul)
{
	bool found = false;
	for(unsigned int i = 0; i < redSouls.size() && !found; ++i)
		if(redSouls[i]->GetType() == soul->GetType())
			found = true;
	
	if(!found)
		redSouls.push_back(soul);
}

