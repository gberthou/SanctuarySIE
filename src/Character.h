#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>

#include "Inventory.h"
#include "Stats.h"
#include "CharacterState.h"
#include "Status.h"
#include "Resources.h"
#include "Gameplay.h"

class Character : public sf::Drawable
{
    public:
        Character();
        virtual ~Character();
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        void AddGold(int amount);
        void AddMana(int amount);
        unsigned int DealDamage(unsigned int power, Status ownStatus, unsigned int defense, Status enemyStatus);
    protected:
    private:
        unsigned int getPower();

        // "Apparent" attributes
        unsigned int lvl;           // Level
        unsigned int hp;            // Current HP
        unsigned int mp;            // Current MP
        unsigned int maxHP;         // Max HP
        unsigned int maxMP;         // Max MP
        Status status;              // Status : buff or debuff
        Stats *baseStats;           // Basic stats
        Stats *effectiveStats;      // Effective stats
        Inventory *inventory;       // Inventory

        // "Hidden" attributes
        sf::Sprite sprite;          // Sprite?
        CharacterState state;       // State
};

#endif // CHARACTER_H
