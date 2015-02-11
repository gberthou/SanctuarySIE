#include "EntitySoul.h"
#include "Resources.h"

EntitySoul::EntitySoul(Soul *soul1):
	soul(soul1)
{
	buildSprite();
}

EntitySoul::~EntitySoul()
{
}
	
void EntitySoul::Start(void)
{
	clock.restart();
}

sf::Int32 EntitySoul::GetTime(void)
{
	return clock.getElapsedTime().asMilliseconds();
}

void EntitySoul::buildSprite(void)
{
	switch(soul->GetSoulType())
	{
		case SOULTYPE_RED:
			sprite.setTexture(Resources::texRedSoul);
			break;

		default:
			break;
	}
}

