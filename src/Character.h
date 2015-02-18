#ifndef CHARACTER_H
#define CHARACTER_H

#include <fstream>

#include "Fighter.h"
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

class Character : public Fighter
{
    public:
        Character(Stats *baseStats, unsigned int maxHP, unsigned int maxMP);
        virtual ~Character();
        void AddGold(int amount);
        void AddMana(int amount);

        virtual void LvlUpStats();
        void EarnExp(int amount);
        
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

		virtual const Stats *GetEffectiveStats() const;

		// Debug purpose only
		void DrawAttack(sf::RenderTarget &target, sf::RenderStates states) const;
   	protected:
		// Inherited
		void updateFighter();
        virtual unsigned int getPower() const;
        virtual unsigned int dealDamage(const Fighter *other) const;
    
	private:    
		void computeEffectiveStats();

		// State methods
		void updateJump(void);
		void updateWalk(void);
		void updateAttack(void);
		void updateSoul(void);
		void attackBehavior(void);
		void blueSoulBehavior(void);

        // "Gameplay" attributes
        unsigned int lvl;           // Level
        unsigned int exp;
        unsigned int expToNextLvl;  // Experience required to level up

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
		
    friend std::ostream &operator<<(std::ostream& out, const Character &c);
    friend std::istream &operator>>(std::istream& out, Character &c);

};

#endif // CHARACTER_H
