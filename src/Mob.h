#ifndef MOB_H
#define MOB_H

#include <vector>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Status.h"
#include "Stats.h"
#include "Path.h"
#include "Entity.h"
#include "Item.h"
#include "Gameplay.h"

enum MobBehavior
{
	NORMAL,
	ATTACKING
};

enum MobType
{
	GIANT_BAT,
	DEVIL,
	DEATH,

    MOB_COUNT
};

struct MobDesc
{
	MobDesc(MobType type1, const sf::Vector2f &pos, Path *path1):
		type(type1),
		position(pos),
		path(path1)
	{
	}

	MobType type;
	sf::Vector2f position;
	Path *path;
};

struct Loot
{
    ItemDesc itemDesc;
    unsigned int dropRate;
};

class Level;
class Soul;

class Mob : public Entity
{
    public:
        Mob(MobType type, Stats *stats, unsigned int maxHP, unsigned int maxMP);
        virtual ~Mob();

        bool Hurt(unsigned int damage);
		void AddLoot(const Loot &lootItem);
		
		// Designed to be private
		void LootMob(unsigned int lck);
		void DropSoul(unsigned int lck);

        void UpdateAI(void);

		void SetLevel(Level *level);
        void SetPath(Path *path);

		Status GetStatus() const;
        const Stats* GetStats() const;
        unsigned int GetExp() const;
    
	private:
		void buildSprite(void);

        unsigned int getPower() const;
        unsigned int dealDamage(unsigned int eDefense, Status eStatus) const;
        void dropItems(const std::vector<ItemDesc> &itemsToDrop);

		Level *level;

        // "Apparent" attributes
		MobType type;
       	unsigned int hp;            // Current HP
       	unsigned int mp;            // Current MP
        unsigned int maxHP;         // Max HP
        unsigned int maxMP;         // Max MP

        unsigned int xpDrop;        // XP dropped
        std::vector<Loot> loot;    // Loot

		Soul *soul;
		unsigned int soulDropRate;

        Status status;              // Status : buff or debuff
        Stats *stats;               // Basic stats
        MobBehavior behavior;       // Behavior
        Path *path;                 // Predefined path
};

#endif // MOB_H
