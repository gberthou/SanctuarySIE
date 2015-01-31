#ifndef ACCESSORY_H
#define ACCESSORY_H

#include "Stuff.h"
#include "Stats.h"
#include "Character.h"

class Accessory : public Stuff
{
    public:
        Accessory(Stats *stats1, unsigned int buyPrice1, unsigned int sellPrice1, sf::String description1);
        virtual ~Accessory();
        virtual void PickUp(Character *character) const;
    protected:
    private:
};

#endif // ACCESSORY_H
