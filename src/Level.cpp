#include <iostream>

#include "Level.h"
#include "MobFactory.h"
#include "ItemFactory.h"
#include "LevelDoor.h"

#define DEBUG_PHYSICS
#define DEBUG_CHARACTER_ATTACK

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

	for(unsigned int i = 0; i < itemDescs.size(); ++i)
		delete itemDescs[i];

	for(unsigned int i = 0; i < items.size(); ++i)
		delete items[i];

	for(unsigned int i = 0; i < souls.size(); ++i)
		delete souls[i];

	if(collisionMap != 0)
		delete collisionMap;
	if(physics != 0)
		delete physics;
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

void Level::AddItemDesc(const LevelItemDesc *levelItemDesc)
{
	itemDescs.push_back(levelItemDesc);
}

void Level::SetCollisionMap(const sf::String &filename)
{
	collisionMapFilename = filename;
}

void Level::MakeReady(Character *character1)
{
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
		if(mob != 0)
		{
			mob->SetLevel(this);
			mob->SetPosition(mobDescs[i]->position);
			mob->SetPath(mobDescs[i]->path);
			mobs.push_back(mob);

			physics->AddEntity(mob);
		}
	}

	for(unsigned int i = 0; i < itemDescs.size(); ++i)
	{
		if(itemDescs[i]->available) // Do not spawn items that are unavailable (story purpose or because they were already collected)
			SpawnItem(itemDescs[i]->desc, itemDescs[i]->position);
	}
}

void Level::Leave(void)
{
	for(unsigned int i = 0; i < mobs.size(); ++i)
		delete mobs[i];
	mobs.clear();

	for(unsigned int i = 0; i < items.size(); ++i)
		delete items[i];
	items.clear();

	for(unsigned int i = 0; i < souls.size(); ++i)
		delete souls[i];
	souls.clear();
	
	if(bg != 0)
	{
		delete bg;
		bg = 0;
	}

	if(collisionMap != 0)
	{
		delete collisionMap;
		collisionMap = 0;
	}

	if(physics != 0)
	{
		delete physics;
		physics = 0;
	}
}
void Level::SpawnEntity(Entity *entity, const sf::Vector2f &position)
{
	entity->SetPosition(position);
	physics->AddEntity(entity);
}

void Level::SpawnItem(const ItemDesc &itemDesc, const sf::Vector2f &position)
{
	Item *item = ItemFactory::CreateItem(itemDesc);
	if(item != 0)
	{
		items.push_back(item);
		SpawnEntity(item, position);
	}
}

void Level::SpawnSoul(EntitySoul *entity, const sf::Vector2f &position)
{
	souls.push_back(entity);
	entity->Start();
	SpawnEntity(entity, position);
}


void Level::AddDoor(LevelDoor *door)
{
	doors.push_back(door);
}

void Level::Update(unsigned int frameCount)
{
	for(unsigned int j = 0; j < frameCount; ++j)
	{
		checkItems();
		updateSouls();	

		for(unsigned int i = 0; i < mobs.size(); ++i)
		{
			mobs[i]->UpdateBehavior();
		}

		character->UpdateBehavior();
		checkCharacterAttacks();

		physics->Update();
	}
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
	sprPhysics.setColor(sf::Color(255,255,255,128));

	target.draw(sprPhysics, states);
#endif

	// Draw mobs
	for(unsigned int i = 0; i < mobs.size(); ++i)
	{
		target.draw(*mobs[i], states);
	}

	// Draw items
	for(unsigned int i = 0; i < items.size(); ++i)
	{
		target.draw(*items[i], states);
	}

	// Draw souls
	for(unsigned int i = 0; i < souls.size(); ++i)
	{
		target.draw(*souls[i], states);
	}

	// Draw character
	target.draw(*character, states);

#ifdef DEBUG_CHARACTER_ATTACK
	character->DrawAttack(target, states);
	
	// Draw doors
	for(unsigned int i = 0; i < doors.size(); ++i)
	{
		AABB hb = doors[i]->GetHitbox();
		sf::RectangleShape shape(hb.GetSize());

		shape.setFillColor(sf::Color(0xFF, 0xFF, 0x00));
		shape.setPosition(hb.GetPosition());
		target.draw(shape, states);
	}
#endif
}

void Level::SetPOV(sf::Vector2f pov)
{
    bg->SetOffset(pov);
}

bool Level::ChangeLevelRequired(IdLevel &id, sf::Vector2f &deltaPosition) const
{
	for(unsigned int i = 0; i < doors.size(); ++i)
	{
		if(character->CollidesWith(doors[i]))
		{
			const LevelDoor *otherDoor = doors[i]->GetTarget();
			
			id = otherDoor->GetIdLevel();
			deltaPosition = otherDoor->GetHitbox().GetPosition() - doors[i]->GetHitbox().GetPosition();
			return true;
		}
	}
	return false;
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

void Level::checkItems(void)
{
	std::vector<Item*>::iterator it = items.begin();
	while(it != items.end())
	{
		if((*it)->CollidesWith(character)) // The character just picked up the item
		{
			std::vector<Item*>::iterator tmp = it;
			Item *item = *it;

			item->PickUp(character);

			physics->RemoveEntity(item);
			it = items.erase(tmp);
		}
		else
			++it;
	}
}

void Level::checkCharacterAttacks(void)
{
	std::vector<Mob*>::iterator mobIt;
	
	// Check attacks against mobs
	for(mobIt = mobs.begin(); mobIt !=  mobs.end(); ++mobIt)
	{
		Mob *mob = *mobIt;
		if(!mob->IsDead() && character->HitMob(mob)) // Mob is dead
		{
			const Stats *stats = character->GetEffectiveStats();

			character->EarnExp(mob->GetExp());
			mob->LootMob(stats->GetLck());
			mob->DropSoul(stats->GetLck());
		}
	}

	// TODO: check attacks against furniture
}

void Level::updateSouls(void)
{
	std::vector<EntitySoul*>::iterator it = souls.begin();
	while(it != souls.end())
	{
		if((*it)->CollidesWith(character))
		{
			std::vector<EntitySoul*>::iterator tmp = it;
			EntitySoul *entity = *it;

			entity->PickUp(character);
			delete entity;
			physics->RemoveEntity(entity);
			it = souls.erase(tmp);
		}
		else
		{
			(*it)->GetCloserTo(character);
			++it;
		}
	}
}

