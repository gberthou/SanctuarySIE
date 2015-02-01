#include "Level.h"
#include "MobFactory.h"

Level::Level(unsigned int x1, unsigned int y1, unsigned int width1, unsigned int height1):
	x(x1),
	y(y1),
	width(width1),
	height(height1)
{
}

Level::~Level()
{
	for(unsigned int i = 0; i < mobDescs.size(); ++i)
		delete mobDescs[i];
	
	for(unsigned int i = 0; i < mobs.size(); ++i)
		delete mobs[i];

	for(unsigned int i = 0; i < doors.size(); ++i)
		delete doors[i];
}

void Level::AddMobDesc(const MobDesc *mobDesc)
{
	mobDescs.push_back(mobDesc);
}

void Level::MakeReady(void)
{
	for(unsigned int i = 0; i < mobs.size(); ++i)
		delete mobs[i];
	mobs.clear();

	for(unsigned int i = 0; i < mobDescs.size(); ++i)
	{
		Mob *mob = MobFactory::CreateMob(mobDescs[i]->type);
		mob->SetPosition(mobDescs[i]->position);
		mob->SetPath(mobDescs[i]->path);
		mobs.push_back(mob);
	}
}

void Level::AddDoor(Level *target, unsigned int lx, unsigned int ly, DoorDirection direction)
{
	doors.push_back(new LevelDoor(target, lx, ly, direction));
}

void Level::Update(void)
{
		for(unsigned int i = 0; i < mobs.size(); ++i)
		{
				mobs[i]->UpdateAI();
		}
}

void Level::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	// Draw mobs
	for(unsigned int i = 0; i < mobs.size(); ++i)
	{
		target.draw(*mobs[i], states);
	}
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

