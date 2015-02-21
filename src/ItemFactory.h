#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include <SFML/System.hpp>

#include "Item.h"
#include "ItemType.h"
#include "Weapon.h"
#include "Armor.h"
#include "Accessory.h"
#include "PickUp.h"

class ItemFactory
{
    public:
        static Weapon* CreateWeapon(WeaponType type);
        static Armor* CreateArmor(ArmorType type);
        static Accessory* CreateAccessory(AccessoryType type);
        static PickUp* CreatePickUp(PickUpType type);
        static Consumable* CreateConsumable(ConsumableType type);
        static Permanent* CreatePermanent(PermanentType type);
        static Item* CreateItem(const ItemDesc &desc);
    protected:
    private:
        ItemFactory();
        virtual ~ItemFactory();
};

#endif // ITEMFACTORY_H
