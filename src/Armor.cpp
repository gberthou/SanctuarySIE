#include "Armor.h"

Armor::Armor(Stats *stats1, unsigned int buyPrice1, unsigned int sellPrice1, sf::String description1):
    Stuff(stats1, buyPrice1, sellPrice1, description1)
{
    //ctor
}

Armor::~Armor()
{
    //dtor
}

void Armor::PickUp() const
{
    // Empty on purpose : cannot pick up armor
}
