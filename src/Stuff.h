#ifndef STUFF_H
#define STUFF_H

#include <set>

#include "Stats.h"
#include "ItemAttribute.h"
#include "Item.h"


class Stuff : public Item
{
    public:
        Stuff(Stats *stats1, unsigned int buyPrice1, unsigned int sellPrice1, sf::String description1);
        virtual ~Stuff();
        void AddAttribute(ItemAttribute attribute1);
        virtual void PickUp() const = 0;
    protected:
        Stats *stats;
        unsigned int buyPrice;
        unsigned int sellPrice;
        sf::String description;
        std::set<ItemAttribute> attributes;
    private:
};

#endif // STUFF_H
