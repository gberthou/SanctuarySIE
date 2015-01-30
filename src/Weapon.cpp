#include "Weapon.h"

Weapon::Weapon(Stats *stats1, unsigned int buyPrice1, unsigned int sellPrice1, sf::String description1):
    Stuff(stats1, buyPrice1, sellPrice1, description1)
{
    //ctor
}

Weapon::~Weapon()
{

}

void Weapon::PickUp(Character *character) const
{
    // Empty on purpose : cannot pick up weapon
}
