#ifndef MOB_H
#define MOB_H

#include <SFML/Graphics.hpp>

#include "Status.h"
#include "Stats.h"
#include "Path.h"

enum MobBehavior
{
	NORMAL,
	ATTACKING
};

class Mob
{
    public:
        Mob();
        virtual ~Mob();
    	
	void SetPath(Path *path);	
    
    protected:
    private:
        // "Apparent" attributes
        unsigned int hp;            // Current HP
        unsigned int mp;            // Current MP
        unsigned int maxHP;         // Max HP
        unsigned int maxMP;         // Max MP
        Status status;             // Status : buff or debuff
        Stats *stats;               // Basic stats
	MobBehavior behavior;       // Behavior
	Path *path;                  // Predefined path

        // "Hidden" attributes
        sf::Sprite sprite;          // Sprite?
};

#endif // MOB_H
