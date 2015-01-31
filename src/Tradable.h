#ifndef TRADABLE_H
#define TRADABLE_H

#include "Item.h"


class Tradable : public Item
{
    public:
        Tradable(sf::String name1, sf::String description1, bool trade1, unsigned int sellPrice1, unsigned int buyPrice1);
        virtual ~Tradable();
        bool IsTradable();
        unsigned int GetSellPrice();
        unsigned int GetBuyPrice();
    protected:
        sf::String name;
        sf::String description;
        bool trade;
        unsigned int buyPrice;
        unsigned int sellPrice;
    private:

};

#endif // TRADABLE_H
