#ifndef ACCESSORY_H
#define ACCESSORY_H

#include "ItemType.h"
#include "Stuff.h"
#include "Stats.h"
#include "Character.h"

class Accessory : public Stuff
{
    public:
        Accessory(AccessoryType accessoryType1, Stats *stats1, sf::String name1, sf::String description1, bool trade1, unsigned int sellPrice1, unsigned int buyPrice1);
        virtual ~Accessory();
        AccessoryType GetAccessoryType() const;
        ItemSubtype GetSubtype() const;
        
    protected:
        AccessoryType accessoryType;
        
    private:
};

#endif // ACCESSORY_H
