#include "LevelFactory.h"
#include "LevelDoor.h"

Level *LevelFactory::CreateLevel(IdLevel idLevel)
{
	Level *level = 0;

	switch(idLevel)
	{
		case CORRIDOR0:
		{
			Path *path;
			AABB *doorHb;
			BgDesc bgDesc;

			level = new Level(10, 9, 3, 1);
			
			// Doors
			doorHb = new AABB(sf::Vector2f(1600 - 3, 470 - 100), sf::Vector2f(3, 100));
			level->AddDoor(new LevelDoor(CORRIDOR1, *doorHb, 0, 1, RIGHT));
			delete doorHb;

			// Backgrounds
			bgDesc.names[0] = sf::String("img/levels/sample/layer0.png");
			bgDesc.names[1] = sf::String("img/levels/sample/layer1.png");
			bgDesc.names[2] = sf::String("img/levels/sample/layer2.png");
			bgDesc.names[3] = sf::String("img/levels/sample/layer3.png");
			level->SetBgDesc(bgDesc);

			// Collision map
			level->SetCollisionMap(sf::String("img/levels/sample/collision.png"));

			// Mobs
			path = new Path();
			path->AddPosition(sf::Vector2f(20, 20));
			path->AddPosition(sf::Vector2f(200, 20));
			path->MakeReady();
			level->AddMobDesc(new MobDesc(GIANT_BAT, sf::Vector2f(10, 20), path));

			path = new Path();
			path->AddPosition(sf::Vector2f(100, 300));
			path->AddPosition(sf::Vector2f(20, 300));
			path->MakeReady();
			level->AddMobDesc(new MobDesc(GIANT_BAT, sf::Vector2f(100, 300), path));
			
			// Items
			level->AddItemDesc(new LevelItemDesc(WEAPON, DAGGER, sf::Vector2f(64, 300)));
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

