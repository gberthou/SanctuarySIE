#include "Item.h"

Item::Item():
    Entity()
{
}

Item::~Item()
{
}

void Item::Drop(sf::Vector2f posToDrop)
{
    pos = posToDrop;
    // autre chose ?
}

ItemType Item::GetType()
{
    return type;
}

