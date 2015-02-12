#ifndef WEAPON_H
#define WEAPON_H

#include <SFML/System.hpp>

#include "Stuff.h"
#include "Stats.h"
#include "Character.h"
#include "AttackAnimation.h"

class Weapon : public Stuff
{
    public:
        Weapon(WeaponType weaponType, Stats *stats1, sf::String name1, sf::String description1, bool trade1, unsigned int sellPrice1, unsigned int buyPrice1, sf::Int32 cooldown);
        virtual ~Weapon();
   
		sf::Int32 GetCooldown(void) const;
	
		static AttackAnimation *GetAttackAnimation(Weapon *weapon);
	private:
		void buildSprite(void);

		WeaponType weaponType;
		sf::Int32 cooldown;
};

#endif // WEAPON_H
