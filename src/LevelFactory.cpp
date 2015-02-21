#include "LevelFactory.h"
#include "LevelDoor.h"

std::map<unsigned int, LevelDoor*> LevelFactory::doors;

static inline unsigned int doorId(IdLevel idLevel, unsigned char idDoor)
{
	return (idLevel << 8) | (idDoor & 0xFF);
}

Level *LevelFactory::CreateLevel(IdLevel idLevel)
{
	Level *level = 0;

	switch(idLevel)
	{
		case CORRIDOR0:
		{
			Path *path;
			BgDesc bgDesc;

			level = new Level(10, 9, 3, 1);
			
			// Doors
			level->AddDoor(getDoor(CORRIDOR0, 0));
			
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

		case CORRIDOR1:
		{
			Path *path;
			BgDesc bgDesc;

			level = new Level(10, 9, 3, 1);
			
			// Doors
			level->AddDoor(getDoor(CORRIDOR1, 0));

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

void LevelFactory::CreateDoors(void)
{
	doors.clear();
	
	// ## Doors allocation ##

	// CORRIDOR0
	doors.insert(std::pair<unsigned int, LevelDoor*>(
				doorId(CORRIDOR0, 0),
				new LevelDoor(CORRIDOR0,
							  AABB(sf::Vector2f(1600 - 3, 470 - 100), sf::Vector2f(3, 100)),
							  //AABB(sf::Vector2f(800 - 3, 470 - 100), sf::Vector2f(3, 100)),
							  1, 0, RIGHT)
				));

	// CORRIDOR1
	doors.insert(std::pair<unsigned int, LevelDoor*>(
				doorId(CORRIDOR1, 0),
				new LevelDoor(CORRIDOR1,
							  AABB(sf::Vector2f(0, 0), sf::Vector2f(3, 70)),
							  0, 0, LEFT)
				));

	// ## Doors association ##
	associateDoors(CORRIDOR0, 0, CORRIDOR1, 0);
}

void LevelFactory::FreeDoors(void)
{
	std::map<unsigned int, LevelDoor*>::iterator it;
	for(it = doors.begin(); it != doors.end(); ++it)
		delete it->second;

	doors.clear();
}

LevelFactory::LevelFactory()
{
}

LevelFactory::~LevelFactory()
{
}

LevelDoor *LevelFactory::getDoor(IdLevel idLevel, unsigned int idDoor)
{
	return doors.find(doorId(idLevel, idDoor))->second;
}

void LevelFactory::associateDoors(IdLevel idLevel1, unsigned int idDoor1, IdLevel idLevel2, unsigned int idDoor2)
{
	LevelDoor *firstDoor = getDoor(idLevel1, idDoor1);
	LevelDoor *secondDoor = getDoor(idLevel2, idDoor2);

	firstDoor->SetTarget(secondDoor);
	secondDoor->SetTarget(firstDoor);
}
