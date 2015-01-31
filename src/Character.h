#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.h"
#include "Inventory.h"
#include "Stats.h"
#include "CharacterState.h"
#include "Status.h"
#include "Resources.h"

class Character : public Entity
{
    public:
        Character();
        virtual ~Character();
        void AddGold(int amount);
        void AddMana(int amount);
    protected:
    private:
        // "Apparent" attributes
        unsigned int lvl;           // Level
        unsigned int hp;            // Current HP
        unsigned int mp;            // Current MP
        unsigned int maxHP;         // Max HP
        unsigned int maxMP;         // Max MP
        Status *status;             // Status : buff or debuff
        Stats *stats;               // Basic stats
        Inventory *inventory;       // Inventory

        // "Hidden" attributes
        CharacterState state;       // State
};

#endif // CHARACTER_H
