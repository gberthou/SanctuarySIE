#include "MobFactory.h"
#include "Resources.h"
#include "AABB.h"

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
	Stats *stats = new Stats();
	Mob *mob = new Mob(GIANT_BAT, stats, 2, 2);
	Loot lootDagger = {{WEAPON, {DAGGER}}, 100};
	AABB hitbox(sf::Vector2f(34, 55));

	mob->SetHitbox(hitbox, sf::Vector2f(50, 0));
	mob->AddLoot(lootDagger);
	return mob;
}

MobFactory::MobFactory()
{
}

MobFactory::~MobFactory()
{
}

