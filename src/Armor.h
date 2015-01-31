#ifndef ARMOR_H
#define ARMOR_H

#include "Stuff.h"
#include "Stats.h"
#include "Character.h"

class Armor : public Stuff
{
    public:
        Armor(Stats *stats1, sf::String name1, sf::String description1, bool trade1, unsigned int sellPrice1, unsigned int buyPrice1);
        virtual ~Armor();
        virtual void PickUp(Character *character) const;
    protected:
    private:
};

#endif // ARMOR_H
