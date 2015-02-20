#include "Item.h"

Item::Item():
    Entity()
{
}

Item::~Item()
{
}

ItemType Item::GetType()
{
    return type;
}

ItemSubtype Item::GetSubtype() const
{
    return (ItemSubtype){-1};
}
