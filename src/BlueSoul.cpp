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
	unsigned int frameCount = clock.GetElapsedFrames();

	switch(type)
	{
		case DEVIL:
			if(frameCount > 0)
			{
				for(unsigned int i = 0; i < frameCount; ++i)
					std::cout << "I'm so evil!" << std::endl;
				clock.restart();
			}
			break;

		case DEATH:
			if(frameCount > 0)
			{
				for(unsigned int i = 0; i < frameCount; ++i)
					std::cout << "Kha kakakaka kha..." << std::endl;
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

