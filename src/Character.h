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
#include "AttackAnimation.h"

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
		bool HitMob(Mob *mob);
        
        void Attack();
		void ReleaseAttack();
		void Jump();
		void ReleaseJump();
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

		// GetActionPoint : Copy the action point into point parameter
		// Return true if there is an attack animation, returns false
		// otherwise.
		bool GetActionPoint(sf::Vector2f &point) const;
		
		unsigned int GetHP() const;
		unsigned int GetMaxHP() const;
		unsigned int GetMP() const;
		unsigned int GetMaxMP() const;
		unsigned int GetLevel() const;
		unsigned int GetExp() const;
		unsigned int GetExpToNextLvl() const;

		const Stats *GetEffectiveStats() const;

		// Debug purpose only
		void DrawAttack(sf::RenderTarget &target, sf::RenderStates states) const;
   	protected:
    private:
        unsigned int getPower() const;
        void updateStats();
        unsigned int dealDamage(unsigned int eDefense, Status eStatus) const;

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

		AttackAnimation *attack;

        // "Hidden" attributes
        CharacterStateJump stateJump;
		CharacterStateWalk stateWalk;
		CharacterStateAttack stateAttack;
		CharacterStateRedSoul stateRedSoul;
		CharacterStateBlueSoul stateBlueSoul;

		FPSClock clWalk;
		sf::Clock clBackDashTimeout;
		sf::Clock clAttack;
		sf::Clock clJumpTimeout;
		sf::Clock clBackDash;
		sf::Clock clRedSoul;
};

#endif // CHARACTER_H
