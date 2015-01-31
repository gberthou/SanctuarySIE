#include "Armor.h"

Armor::Armor(Stats *stats1, sf::String name1, sf::String description1, bool trade1, unsigned int sellPrice1, unsigned int buyPrice1):
    Stuff(stats1, name1, description1, trade1, sellPrice1, buyPrice1)
{
    //ctor
}

Armor::~Armor()
{
    //dtor
}

void Armor::PickUp(Character *character) const
{
    // Empty on purpose : cannot pick up armor
}
