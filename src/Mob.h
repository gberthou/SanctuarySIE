#ifndef MOB_H
#define MOB_H

#include <SFML/Graphics.hpp>

#include "Status.h"
#include "Stats.h"

class Mob
{
    public:
        Mob();
        virtual ~Mob();
        unsigned int getPower();
        bool Hurt(unsigned int damage);
        unsigned int DealDamage(unsigned int power, Status ownStatus, unsigned int defense, Status enemyStatus);
    protected:
    private:
        // "Apparent" attributes
        unsigned int hp;            // Current HP
        unsigned int mp;            // Current MP
        unsigned int maxHP;         // Max HP
        unsigned int maxMP;         // Max MP
        Status status;             // Status : buff or debuff
        Stats *stats;               // Basic stats

        // "Hidden" attributes
        sf::Sprite sprite;          // Sprite?
};

#endif // MOB_H
