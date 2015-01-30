#include "ItemFactory.h"

ItemFactory::ItemFactory()
{
    //ctor
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

}

Accessory* ItemFactory::CreateAccessory(AccessoryType type)
{

}

ItemFactory::~ItemFactory()
{
    //dtor
}
