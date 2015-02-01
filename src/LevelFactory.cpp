#include "LevelFactory.h"

Level *LevelFactory::CreateLevel(TypeLevel typeLevel)
{
	Level *level = 0;

	switch(typeLevel)
	{
		case CORRIDOR0:
		{
			level = new Level(0, 0, 1, 1);
			level->AddMobDesc(new MobDesc(GIANT_BAT, sf::Vector2f(10, 20), 0));
			level->AddMobDesc(new MobDesc(GIANT_BAT, sf::Vector2f(100, 100), 0));
			break;
		}

		default:
			break;
	}

	return level;
}

LevelFactory::LevelFactory()
{
}

LevelFactory::~LevelFactory()
{
}

