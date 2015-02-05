#include <iostream>

#include "RedSoul.h"

RedSoul::RedSoul(MobType mobType, sf::Int32 cooldown1):
	Soul(mobType, SOULTYPE_RED),
	cooldown(cooldown1)
{
}

RedSoul::~RedSoul()
{
}

void RedSoul::Use(void)
{
	switch(type)
	{
		case GIANT_BAT:
			useGiantBat();
			break;

		default:
			break;
	}
}

sf::Int32 RedSoul::GetCooldown(void) const
{
	return cooldown;
}

void RedSoul::useGiantBat(void)
{
	std::cout << "I'm batman!" << std::endl;
}

