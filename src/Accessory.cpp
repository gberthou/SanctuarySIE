#include "Accessory.h"

Accessory::Accessory(Stats *stats1, unsigned int buyPrice1, unsigned int sellPrice1, sf::String description1):
    Stuff(stats1, buyPrice1, sellPrice1, description1)
{
    //ctor
}

Accessory::~Accessory()
{
    //dtor
}

void Accessory::PickUp() const
{
    // Empty on purpose : cannot pick up accessory
}
