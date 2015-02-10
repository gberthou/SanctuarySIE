#include "Stuff.h"

Stuff::Stuff(Stats *stats1, sf::String name1, sf::String description1, bool trade1, unsigned int sellPrice1, unsigned int buyPrice1):
    Tradable(name1, description1, trade1, sellPrice1, buyPrice1)
{
    stats = stats1;
//    type = STUFF;
}

Stuff::~Stuff()
{
    delete stats;
}

void Stuff::AddAttribute(ItemAttribute attribute1)
{
    attributes.insert(attribute1);
}

void Stuff::PickUp(Character *character)
{
	character->GetInventory()->LootItem(this);
}

ItemEffect Stuff::GetEffect()
{
    return effect;
}

Stats* Stuff::GetStats()
{
    return stats;
}
