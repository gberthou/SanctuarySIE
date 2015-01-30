#include "ItemFactory.h"

ItemFactory::ItemFactory()
{
    //ctor
}

ItemFactory::~ItemFactory()
{
    //dtor
}

Weapon* ItemFactory::CreateWeapon(WeaponType type)
{
    switch(type)
    {
        //case :
        //    return new ;
        default:
            return 0;
    }
}

Armor* ItemFactory::CreateArmor(ArmorType type)
{
    switch(type)
    {
        //case :
        //    return new ;
        default:
            return 0;
    }
}

Accessory* ItemFactory::CreateAccessory(AccessoryType type)
{
    switch(type)
    {
        //case :
        //    return new ;
        default:
            return 0;
    }
}
