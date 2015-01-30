#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include <SFML/System.hpp>

#include "Item.h"
#include "ItemType.h"
#include "Weapon.h"
#include "Armor.h"
#include "Accessory.h"

class ItemFactory
{
    public:
        ItemFactory();
        virtual ~ItemFactory();
        Weapon* CreateWeapon(WeaponType type);
        Armor* CreateArmor(ArmorType type);
        Accessory* CreateAccessory(AccessoryType type);
    protected:
    private:
};

#endif // ITEMFACTORY_H
