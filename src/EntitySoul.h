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
		sf::Int32 GetTime(void);

		void GetCloserTo(Entity *entity);
	
	private:
		void buildSprite(void);

		Soul *soul;
		sf::Clock clock;
};

#endif

