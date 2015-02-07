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
#include "Orientation.h"
#include "FPSClock.h"

class Item;

class Character : public Entity
{
    public:
        Character();
        virtual ~Character();
        void AddGold(int amount);
        void AddMana(int amount);

        virtual void LvlUpStats();
        void EarnExp(int amount);
        
		bool Hurt(unsigned int damage);
        
        void Attack();
		void Jump();
		void Walk(Orientation orientation);
		void BackDash();
		void ReleaseBackDash();
        void StopWalking(Orientation orientation);
		void UseRedSoul();
		void UseBlueSoul();
		void ReleaseBlueSoul();
		void UpdateStates();

		Inventory *GetInventory() const;
		SoulSet *GetSoulSet() const;
   	protected:
    private:
        unsigned int getPower();
        void updateStats();
        unsigned int dealDamage(unsigned int power, Status ownStatus, unsigned int defense, Status enemyStatus);

		// State methods
		void attackBehavior(void);
		void blueSoulBehavior(void);

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

		Orientation orientation;

        // "Hidden" attributes
        CharacterStateJump stateJump;
		CharacterStateWalk stateWalk;
		CharacterStateAttack stateAttack;
		CharacterStateRedSoul stateRedSoul;
		CharacterStateBlueSoul stateBlueSoul;

		FPSClock clWalk;
		sf::Clock clBackDashTimeout;
		sf::Clock clAttack;
		sf::Clock clJump;
		sf::Clock clJumpTimeout;
		sf::Clock clBackDash;
		sf::Clock clRedSoul;
};

#endif // CHARACTER_H
