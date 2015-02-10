#ifndef ACCESSORY_H
#define ACCESSORY_H

#include "Stuff.h"
#include "Stats.h"
#include "Character.h"

class Accessory : public Stuff
{
    public:
        Accessory(Stats *stats1, sf::String name1, sf::String description1, bool trade1, unsigned int sellPrice1, unsigned int buyPrice1);
        virtual ~Accessory();
    protected:
    private:
};

#endif // ACCESSORY_H
