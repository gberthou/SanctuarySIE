#include <iostream>
#include <cstdlib>

#include "Mob.h"
#include "Resources.h"
#include "Level.h"
#include "ItemFactory.h"
#include "SoulManager.h"
#include "EntitySoul.h"

const sf::Vector2f INITIAL_SOUL_VELOCITY(500, 0);

static inline float frand()
{
	return rand() / (float) RAND_MAX;
}

// ---- PUBLIC ----

Mob::Mob(MobType type1, Stats *stats1, unsigned int maxHP1, unsigned int maxMP1):
	Fighter(stats1, maxHP1, maxMP1),
	level(0),
	type(type1),
	soul(SoulManager::GetSoul(type1)),
	behavior(NORMAL),
	path(0)
{
	buildSprite();
}

Mob::~Mob()
{
    if(path != 0)
	    delete path;
}

// #### LOOT METHODS ####
void Mob::AddLoot(const Loot &lootItem)
{
	loot.push_back(lootItem);
}

void Mob::LootMob(unsigned int lck)
{
    // Home-made algorithm for loot-%age
    unsigned int realDropRate = 0;
    std::vector<ItemDesc> itemsToDrop;

    for(unsigned int i=0; i<loot.size(); ++i)
    {
        realDropRate = loot[i].dropRate + (int)((float)lck/(float)MAX_STAT)*MAX_ADD_DROP_RATE;
        realDropRate = (realDropRate > 100) ? 100 : realDropRate;

        if((unsigned int)(rand() % 101) < realDropRate)
            itemsToDrop.push_back(loot[i].itemDesc);
    }
    if(itemsToDrop.size() > 0)
        dropItems(itemsToDrop);
}

// #### Drop Soul ####
void Mob::DropSoul(unsigned int lck)
{
	EntitySoul *entity = new EntitySoul(soul);
	AABB hb(sf::Vector2f(32, 32));
	sf::Vector2f p = hitbox.GetPosition() + (hitbox.GetSize() - hb.GetSize()) / 2.f;

	entity->SetHitbox(hitbox, sf::Vector2f(0, 0));
	entity->SetMapCollisionEnabled(false);
	entity->SetVelocity(INITIAL_SOUL_VELOCITY);
	level->SpawnSoul(entity, p);
}

// #### IA METHODS ####

void Mob::UpdateAI(void)
{
	const float EPSILON = 16; // Warning : may be capricious if the initial mob position is not adapted to the
							 // collision map (ie. if the mob is a few pixels above the local floor)

	if(behavior == NORMAL)
	{
		sf::Vector2f objective = path->GetNextPosition();
		sf::Vector2f diff = objective - GetPos();

		if(diff.x * diff.x + diff.y * diff.y < EPSILON)
		{
			path->PositionReached();
		}
		else if(diff.x > 0) // Objective is on the right
		{
			AddPosition(sf::Vector2f(1, 0));
		}
		else
		{
			AddPosition(sf::Vector2f(-1, 0));
		}
	}
}

// #### SETTERS ####

void Mob::SetPath(Path *path1)
{
	path = path1;
}

void Mob::SetLevel(Level *level1)
{
	level = level1;
}

// #### GETTERS ####

const Stats *Mob::GetEffectiveStats() const
{
	return baseStats;
}

unsigned int Mob::GetExp() const
{
    return xpDrop;
}

// ---- PRIVATE ----

void Mob::buildSprite(void)
{
	switch(type)
	{
		case GIANT_BAT:
			sprite.setTexture(Resources::texGiantBat);
			break;
		
		default:
			break;
	}
}


// #### DAMAGE METHODS ####

unsigned int Mob::getPower() const
{
    return baseStats->GetAtt();
}

unsigned int Mob::dealDamage(const Fighter *other) const
{
    unsigned int damage = 0;
    unsigned int power = getPower();
	unsigned int eDefense = other->GetEffectiveStats()->GetDef();
	damage = (power - eDefense/2)*(MAX_STAT - eDefense)/MAX_STAT;
    return damage;
}

// #### LOOT METHODS ####

void Mob::dropItems(const std::vector<ItemDesc> &itemsToDrop)
{
    if(itemsToDrop.size() != 0)
    {
        sf::Vector2f newPos = GetPos();
       
		level->SpawnItem(itemsToDrop[0], newPos);
        for(unsigned int i = 1; i < itemsToDrop.size(); ++i)
        {
            // random offset between -X_SIZE_ITEM and +X_SIZE_ITEM
            newPos.x = GetPos().x + ((i%2 == 0) ? 2*X_SIZE_ITEM - frand()*0.7*X_SIZE_ITEM : -X_SIZE_ITEM + frand()*0.7*X_SIZE_ITEM);
			level->SpawnItem(itemsToDrop[i], newPos);
		}
    }
}

