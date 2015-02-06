#include <iostream>

#include "BlueSoul.h"

BlueSoul::BlueSoul(MobType mobType, BlueSoulBehavior behavior1):
	Soul(mobType, SOULTYPE_BLUE),
	clock(60),
	behavior(behavior1),
	beingUsed(false)
{
}

BlueSoul::~BlueSoul()
{
}

void BlueSoul::Use(void)
{
	unsigned int frameCount;

	switch(type)
	{
		case DEVIL:
			frameCount = clock.GetElapsedFrames();
			if(frameCount > 0)
			{
				std::cout << "I'm so evil!" << std::endl;
				clock.restart();
			}
			break;
		default:
			break;
	}

	if(!beingUsed)
	{
		beingUsed = true;
		clock.restart();
	}
}

void BlueSoul::StopUsing(void)
{
	beingUsed = false;
}

BlueSoulBehavior BlueSoul::GetBehavior(void) const
{
	return behavior;
}

