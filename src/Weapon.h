#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include "Stats.h"

class Weapon : public Item
{
    public:
        Weapon(Stats *stats1);
        virtual ~Weapon();
    protected:
    private:

};

#endif // WEAPON_H
