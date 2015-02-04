#include <SFML/System.hpp>

#include "Tradable.h"

Tradable::Tradable(sf::String name1, sf::String description1, bool trade1, unsigned int sellPrice1, unsigned int buyPrice1):
    Item()
{
    type = TRADABLE;
}

Tradable::~Tradable()
{
    //dtor
}

bool Tradable::IsTradable()
{
    return trade;
}

unsigned int Tradable::GetSellPrice()
{
    return sellPrice;
}

unsigned int Tradable::GetBuyPrice()
{
    return buyPrice;
}
