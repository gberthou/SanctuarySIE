#include "Level.h"
#include "MobFactory.h"

#define DEBUG_PHYSICS

Level::Level(unsigned int x1, unsigned int y1, unsigned int width1, unsigned int height1):
	x(x1),
	y(y1),
	width(width1),
	height(height1),
	bg(0),
	collisionMap(0),
	physics(0)
{
}

Level::~Level()
{
	for(unsigned int i = 0; i < mobDescs.size(); ++i)
		delete mobDescs[i];
	
	for(unsigned int i = 0; i < mobs.size(); ++i)
		delete mobs[i];

	delete collisionMap;

	for(unsigned int i = 0; i < doors.size(); ++i)
		delete doors[i];
}

void Level::SetBgDesc(const BgDesc &desc)
{
	for(unsigned int i = 0; i < BG_LAYERS; ++i)
		bgDesc.names[i] = desc.names[i];
}

void Level::AddMobDesc(const MobDesc *mobDesc)
{
	mobDescs.push_back(mobDesc);
}

void Level::SetCollisionMap(const sf::String &filename)
{
	collisionMapFilename = filename;
}

void Level::MakeReady(Character *character1)
{
	Leave();
	
	collisionMap = new sf::Image();
	collisionMap->loadFromFile(collisionMapFilename);
	
	physics = new Physics(collisionMap);
	
	character = character1;
	physics->AddEntity(character);

	bg = new LevelBg();
	for(unsigned int i = 0; i < BG_LAYERS; ++i)
	{
		if(!bgDesc.names[i].isEmpty())
			bg->SetLayer(i, bgDesc.names[i]);
	}

	for(unsigned int i = 0; i < mobDescs.size(); ++i)
	{
		Mob *mob = MobFactory::CreateMob(mobDescs[i]->type);
		mob->SetPosition(mobDescs[i]->position);
		mob->SetPath(mobDescs[i]->path);
		mobs.push_back(mob);
		
		physics->AddEntity(mob);
	}
}

void Level::Leave(void)
{
	for(unsigned int i = 0; i < mobs.size(); ++i)
		delete mobs[i];
	mobs.clear();
	
	if(bg != 0)
		delete bg;
	
	if(collisionMap != 0)
		delete collisionMap;

	if(physics != 0)
		delete physics;
}

void Level::AddDoor(Level *target, unsigned int lx, unsigned int ly, DoorDirection direction)
{
	doors.push_back(new LevelDoor(target, lx, ly, direction));
}

void Level::Update(unsigned int frameCount)
{
		for(unsigned int i = 0; i < mobs.size(); ++i)
		{
				mobs[i]->UpdateAI();
		}

		physics->Update();
}

void Level::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	// Draw background
	target.draw(*bg, states);

#ifdef DEBUG_PHYSICS
	sf::Texture tex;
	sf::Sprite sprPhysics;

	tex.loadFromImage(*collisionMap);
	sprPhysics.setTexture(tex);

	target.draw(sprPhysics, states);
#endif

	// Draw mobs
	for(unsigned int i = 0; i < mobs.size(); ++i)
	{
		target.draw(*mobs[i], states);
	}

	// Draw character
	target.draw(*character, states);
}

unsigned int Level::GetX(void) const
{
	return x;
}

unsigned int Level::GetY(void) const
{
	return y;
}
		
unsigned int Level::GetWidth(void) const
{
	return width;
}

unsigned int Level::GetHeight(void) const
{
	return height;
}

const std::vector<LevelDoor*> &Level::GetDoors(void) const
{
	return doors;
}

