#include "Weapon.h"

Weapon::Weapon(Stats *stats1, sf::String name1, sf::String description1, bool trade1, unsigned int sellPrice1, unsigned int buyPrice1, sf::Int32 cooldown1):
    Stuff(stats1, name1, description1, trade1, sellPrice1, buyPrice1),
	cooldown(cooldown1)
{
    type = WEAPON;
}

Weapon::~Weapon()
{

}

void Weapon::PickUp(Character *character) const
{
    // Empty on purpose : cannot pick up weapon
}

sf::Int32 Weapon::GetCooldown(void) const
{
	return cooldown;
}

