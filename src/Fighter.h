#ifndef FIGHTER_H
#define FIGHTER_H

#include <iostream>

#include "Entity.h"
#include "Stats.h"
#include "Status.h"

class Fighter : public Entity
{
	public:
		Fighter(Stats *baseStats, unsigned int maxHP, unsigned int maxMP);
		virtual ~Fighter();

		void UpdateBehavior();
		bool Hurt(unsigned int damage);

		bool IsDead() const;	
		Status GetStatus() const;
		virtual const Stats *GetEffectiveStats() const = 0;

	protected:
		virtual void updateFighter() = 0;
		virtual unsigned int getPower() const = 0;
		virtual unsigned int dealDamage(const Fighter *other) const = 0;
		
		unsigned int hp;    // Current HP
		unsigned int mp;    // Current MP
        unsigned int maxHP; // Max HP
        unsigned int maxMP; // Max MP

		Status status;
		Stats *baseStats;
};

#endif

