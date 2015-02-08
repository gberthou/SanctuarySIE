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
    SetPosition(posToDrop);
    // autre chose ?
}

ItemType Item::GetType()
{
    return type;
}

