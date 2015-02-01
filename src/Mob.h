#ifndef MOB_H
#define MOB_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Status.h"
#include "Stats.h"
#include "Path.h"
#include "Entity.h"

enum MobBehavior
{
	NORMAL,
	ATTACKING
};

enum MobType
{
	GIANT_BAT
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

class Mob : public Entity
{
    public:
        Mob(MobType type, const sf::Texture &texture);
        virtual ~Mob();
        unsigned int getPower();
        bool Hurt(unsigned int damage);
        unsigned int DealDamage(unsigned int power, Status ownStatus, unsigned int defense, Status enemyStatus);
        void SetPath(Path *path);
		void UpdateAI(void);
    protected:
    private:
        // "Apparent" attributes
		MobType type;
       	unsigned int hp;            // Current HP
        unsigned int mp;            // Current MP
        unsigned int maxHP;         // Max HP
        unsigned int maxMP;         // Max MP
        Status status;              // Status : buff or debuff
        Stats *stats;               // Basic stats
        MobBehavior behavior;       // Behavior
        Path *path;                 // Predefined path
};

#endif // MOB_H
