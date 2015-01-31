#ifndef WEAPON_H
#define WEAPON_H

#include "Stuff.h"
#include "Stats.h"
#include "Character.h"

class Weapon : public Stuff
{
    public:
        Weapon(Stats *stats1, sf::String name1, sf::String description1, bool trade1, unsigned int sellPrice1, unsigned int buyPrice1);
        virtual ~Weapon();
        virtual void PickUp(Character *character) const;
    protected:
    private:

};

#endif // WEAPON_H
