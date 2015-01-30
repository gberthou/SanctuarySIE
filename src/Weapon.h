#ifndef WEAPON_H
#define WEAPON_H

#include "Stuff.h"
#include "Stats.h"

class Weapon : public Stuff
{
    public:
        Weapon(Stats *stats1, unsigned int buyPrice1, unsigned int sellPrice1, sf::String description1);
        virtual ~Weapon();
        virtual void PickUp() const;
    protected:
    private:

};

#endif // WEAPON_H
