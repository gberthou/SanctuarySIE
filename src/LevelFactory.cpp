#include "LevelFactory.h"

Level *LevelFactory::CreateLevel(TypeLevel typeLevel)
{
	Level *level = 0;

	switch(typeLevel)
	{
		case CORRIDOR0:
		{
			Path *path;
			BgDesc bgDesc;

			level = new Level(0, 0, 1, 1);

			bgDesc.names[0] = "img/levels/sample/layer0.png";
			bgDesc.names[1] = "img/levels/sample/layer1.png";
			bgDesc.names[2] = "img/levels/sample/layer2.png";
			bgDesc.names[3] = "img/levels/sample/layer3.png";

			level->SetBgDesc(bgDesc);

			path = new Path();
			path->AddPosition(sf::Vector2f(10, 20));
			path->AddPosition(sf::Vector2f(200, 20));
			path->MakeReady();
			level->AddMobDesc(new MobDesc(GIANT_BAT, sf::Vector2f(10, 20), path));

			path = new Path();
			path->AddPosition(sf::Vector2f(100, 100));
			path->AddPosition(sf::Vector2f(0, 100));
			path->MakeReady();
			level->AddMobDesc(new MobDesc(GIANT_BAT, sf::Vector2f(100, 100), path));
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

