#include "Permanent.h"

Permanent::Permanent(sf::String name1, sf::String description1, bool trade1, unsigned int sellPrice1, unsigned int buyPrice1):
    Tradable(name1, description1, trade1, sellPrice1, buyPrice1)
{
    //ctor
}

Permanent::~Permanent()
{
    //dtor
}
