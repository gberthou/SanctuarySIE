#include "Item.h"

Item::Item(Stats *stats1)
{
    stats = stats1;

}

Item::~Item()
{
    delete stats;

}
