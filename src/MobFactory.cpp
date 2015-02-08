#include "MobFactory.h"
#include "Resources.h"

Mob *MobFactory::CreateMob(MobType type)
{
	switch(type)
	{
		case GIANT_BAT:
			return CreateGiantBat();
		default:
			break;
	}
	return 0;
}

Mob *MobFactory::CreateGiantBat(void)
{
	Mob *mob = new Mob(GIANT_BAT);
	Loot lootDagger = {{WEAPON, DAGGER}, 100};

	mob->AddLoot(lootDagger);
	return mob;
}

MobFactory::MobFactory()
{
}

MobFactory::~MobFactory()
{
}

