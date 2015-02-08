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
	return new Mob(GIANT_BAT);
}

MobFactory::MobFactory()
{
}

MobFactory::~MobFactory()
{
}

