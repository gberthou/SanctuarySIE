#include "MobFactory.h"
#include "Resources.h"

Mob *MobFactory::CreateGiantBat(void)
{
	return new Mob(Resources::texGiantBat);
}

MobFactory::MobFactory()
{
}

MobFactory::~MobFactory()
{
}

