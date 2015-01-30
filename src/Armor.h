#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"
#include "Stats.h"

class Armor : public Item
{
    public:
        Armor(Stats *stats1);
        virtual ~Armor();
    protected:
    private:
};

#endif // ARMOR_H
