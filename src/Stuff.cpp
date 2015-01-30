#include "Stuff.h"

Stuff::Stuff(Stats *stats1, unsigned int buyPrice1, unsigned int sellPrice1, sf::String description1):
    Item()
{
    stats = stats1;
    buyPrice = buyPrice1;
    sellPrice = sellPrice1;
    description = description1;
}

Stuff::~Stuff()
{
    delete stats;
}

void Stuff::AddAttribute(ItemAttribute attribute1)
{
    attributes.insert(attribute1);
}
