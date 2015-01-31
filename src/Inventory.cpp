#include "Inventory.h"
#include "Armor.h"
#include "Weapon.h"
#include "Accessory.h"
#include "Item.h"

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

void Inventory::AddGold(int amount)
{
    gold += amount;
}

void Inventory::Sell(Item* toSell)
{

}
