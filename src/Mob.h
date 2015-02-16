#ifndef MOB_H
#define MOB_H

#include <vector>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Status.h"
#include "Stats.h"
#include "Path.h"
#include "Fighter.h"
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

class Mob : public Fighter
{
    public:
        Mob(MobType type, Stats *stats, unsigned int maxHP, unsigned int maxMP);
        virtual ~Mob();

		void AddLoot(const Loot &lootItem);
		
		// Designed to be private
		void LootMob(unsigned int lck);
		void DropSoul(unsigned int lck);

		void SetLevel(Level *level);
        void SetPath(Path *path);

        unsigned int GetExp() const;
		
		// Inherited
		const Stats *GetEffectiveStats() const;
   
	protected:
		// Inherited
		void updateFighter();
        unsigned int getPower() const;
        unsigned int dealDamage(const Fighter *other) const;
	
	private:
		void buildSprite(void);
		
		// AI Methods
		void normalBehavior(void);
		void attackBehavior(void);

        void dropItems(const std::vector<ItemDesc> &itemsToDrop);

		Level *level;

        // "Apparent" attributes
		MobType type;

        unsigned int xpDrop;       // XP dropped
        std::vector<Loot> loot;    // Loot

		Soul *soul;
		unsigned int soulDropRate;

        MobBehavior behavior;       // Behavior
        Path *path;                 // Predefined path
};

#endif // MOB_H
