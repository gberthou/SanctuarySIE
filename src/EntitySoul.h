#ifndef ENTITYSOUL_H
#define ENTITYSOUL_H

#include <SFML/System.hpp>

#include "Entity.h"
#include "Soul.h"

class EntitySoul : public Entity
{
	public:
		EntitySoul(Soul *soul);
		virtual ~EntitySoul();

		void Start(void);

		void GetCloserTo(Entity *entity);
		void PickUp(Character *character);

	private:
		void buildSprite(void);

		Soul *soul;
		sf::Clock clock;
};

#endif

