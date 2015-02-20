#ifndef ARMOR_H
#define ARMOR_H

#include "Stuff.h"
#include "Stats.h"
#include "Character.h"

class Armor : public Stuff
{
    public:
        Armor(ArmorType narmorType, Stats *stats1, sf::String name1, sf::String description1, bool trade1, unsigned int sellPrice1, unsigned int buyPrice1);
        virtual ~Armor();
        ArmorType GetArmorType() const;
        ItemSubtype GetSubtype() const;
        
    protected:
        ArmorType armorType;
        
    private:
};

#endif // ARMOR_H
