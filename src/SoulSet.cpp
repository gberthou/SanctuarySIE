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

		case SOULTYPE_BLUE:
			addBlueSoul((BlueSoul*) soul);
			break;

		default:
			break;
	}
}


// Red souls
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


// Blue souls
void SoulSet::EquipBlueSoul(std::vector<BlueSoul*>::const_iterator it)
{
	blueSoul = *it;
}

BlueSoul *SoulSet::GetBlueSoul() const
{
    return blueSoul;
}

const std::vector<BlueSoul*> &SoulSet::GetBlueSouls() const
{
	return blueSouls;
}


// Yellow souls
YellowSoul *SoulSet::GetYellowSoul() const
{
    return yellowSoul;
}


void SoulSet::addRedSoul(RedSoul *soul)
{
	bool found = false;
	for(unsigned int i = 0; i < redSouls.size() && !found; ++i)
		if(redSouls[i] == soul)
			found = true;
	
	if(!found)
		redSouls.push_back(soul);
}

void SoulSet::addBlueSoul(BlueSoul *soul)
{
	bool found = false;
	for(unsigned int i = 0; i < blueSouls.size() && !found; ++i)
		if(blueSouls[i] == soul)
			found = true;
	
	if(!found)
		blueSouls.push_back(soul);
}

