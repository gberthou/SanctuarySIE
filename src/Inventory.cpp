#include "Inventory.h"

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
