#ifndef ARMOR_H
#define ARMOR_H

#include "Stuff.h"
#include "Stats.h"

class Armor : public Stuff
{
    public:
        Armor(Stats *stats1, unsigned int buyPrice1, unsigned int sellPrice1, sf::String description1);
        virtual ~Armor();
        virtual void PickUp() const;
    protected:
    private:
};

#endif // ARMOR_H
