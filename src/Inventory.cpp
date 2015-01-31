#include "Inventory.h"
#include "Armor.h"
#include "Weapon.h"
#include "Accessory.h"

Inventory::Inventory()
{
    //ctor
}

Inventory::~Inventory()
{
    delete armor;
    delete weapon;
    delete accessory;
}
