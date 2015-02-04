#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.h"
#include "Inventory.h"
#include "SoulSet.h"
#include "Stats.h"
#include "CharacterState.h"
#include "Status.h"
#include "Resources.h"
#include "Gameplay.h"
class Item;

class Character : public Entity
{
    public:
        Character();
        virtual ~Character();
        void AddGold(int amount);
        void AddMana(int amount);
        void EarnExp(int amount);
        bool Hurt(unsigned int damage);
        void Walk(sf::Vector2f direction);
        virtual void LvlUpStats();
        void LootItem(Item *item);
        void Attack();
    protected:
    private:
        unsigned int getPower();
        void updateStats();
        unsigned int dealDamage(unsigned int power, Status ownStatus, unsigned int defense, Status enemyStatus);


        // "Gameplay" attributes
        unsigned int lvl;           // Level
        unsigned int hp;            // Current HP
        unsigned int mp;            // Current MP
        unsigned int exp;

        unsigned int maxHP;         // Max HP
        unsigned int maxMP;         // Max MP
        unsigned int expToNextLvl;  // Experience required to level up

        Status status;              // Status : buff or debuff
        Stats *baseStats;           // Basic stats
        Stats *effectiveStats;      // Effective stats
        Inventory *inventory;       // Inventory
        SoulSet *soulSet;           // SoulSet

        // "Hidden" attributes
        CharacterState state;       // State
};

#endif // CHARACTER_H
