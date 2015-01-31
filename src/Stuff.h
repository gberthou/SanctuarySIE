#ifndef STUFF_H
#define STUFF_H

#include <set>

#include "Stats.h"
#include "ItemAttribute.h"
#include "Tradable.h"
#include "Character.h"


class Stuff : public Tradable
{
    public:
        Stuff(Stats *stats1, sf::String name1, sf::String description1, bool trade1, unsigned int sellPrice1, unsigned int buyPrice1);
        virtual ~Stuff();
        void AddAttribute(ItemAttribute attribute1);
        virtual void PickUp(Character *character) const = 0;
    protected:
        Stats *stats;
        std::set<ItemAttribute> attributes;
    private:
};

#endif // STUFF_H
