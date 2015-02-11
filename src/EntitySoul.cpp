#include <cmath>

#include "EntitySoul.h"
#include "Resources.h"
#include "Character.h"

const float SOUL_ATTRACT_FORCE = 16;
const float SOUL_BRAKE_FORCE = 2;

static sf::Vector2f normalize(const sf::Vector2f &v)
{
	float d = v.x * v.x + v.y * v.y;
	if(d != 0)
	{
		return v / (float)sqrt(d);
	}
	return sf::Vector2f(0, 0);
}

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

void EntitySoul::GetCloserTo(Entity *entity)
{
		sf::Vector2f d = normalize(entity->GetCenter() - GetCenter()); // Gravitational component
		sf::Vector2f brake = normalize(-GetVelocity());
		sf::Vector2f impulse = d * SOUL_ATTRACT_FORCE + brake * SOUL_BRAKE_FORCE;
		AddImpulse(impulse);
}

void EntitySoul::PickUp(Character *character)
{
	character->GetSoulSet()->AddSoul(soul);
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

