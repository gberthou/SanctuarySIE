#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include <SFML/System.hpp>

#include "Item.h"
#include "ItemType.h"
#include "Weapon.h"
#include "Armor.h"
#include "Accessory.h"
#include "PickUpItem.h"

class ItemFactory
{
    public:
        Weapon* CreateWeapon(WeaponType type);
        Armor* CreateArmor(ArmorType type);
        Accessory* CreateAccessory(AccessoryType type);
        PickUpItem* CreatePickUpItem(PickUpItemType type);
    protected:
    private:
        ItemFactory();
        virtual ~ItemFactory();
};

#endif // ITEMFACTORY_H
