#include "Inventory.h"
#include "Armor.h"
#include "Weapon.h"
#include "Accessory.h"
#include "Consumable.h"
#include "Permanent.h"
#include "Tradable.h"

Inventory::Inventory()
{
    //ctor
}

Inventory::~Inventory()
{
    delete armor;
    delete weapon;
    delete accessory;

    for(unsigned int i = 0; i < armors.size(); ++i)
        delete armors[i];
    for(unsigned int i = 0; i < weapons.size(); ++i)
        delete weapons[i];
    for(unsigned int i = 0; i < accessories.size(); ++i)
        delete accessories[i];
    for(unsigned int i = 0; i < consumables.size(); ++i)
        delete consumables[i];
    for(unsigned int i = 0; i < permanents.size(); ++i)
        delete permanents[i];
}

void Inventory::AddGold(int amount)
{
    gold += amount;
}

void Inventory::sellItem(Tradable *toSell)
{
    unsigned int price = toSell->GetSellPrice();
    gold += price;
}

void Inventory::Sell(std::vector<Armor*>::iterator armorIt)
{
    if((*armorIt)->IsTradable())
    {
        sellItem(*armorIt);
        armors.erase(armorIt);
    }
    else
    {
        // Play a "bip"
    }
}

void Inventory::Sell(std::vector<Weapon*>::iterator weaponIt)
{
    if((*weaponIt)->IsTradable())
    {
        sellItem(*weaponIt);
        weapons.erase(weaponIt);
    }
    else
    {
        // Play a "bip"
    }
}

void Inventory::Sell(std::vector<Accessory*>::iterator accessoryIt)
{
    if((*accessoryIt)->IsTradable())
    {
        sellItem(*accessoryIt);
        accessories.erase(accessoryIt);
    }
    else
    {
        // Play a "bip"
    }
}

void Inventory::Sell(std::vector<Consumable*>::iterator consumableIt)
{
    if((*consumableIt)->IsTradable())
    {
        sellItem(*consumableIt);
        consumables.erase(consumableIt);
    }
    else
    {
        // Play a "bip"
    }
}

bool Inventory::buyItem(Tradable *toBuy)
{
    unsigned int price = toBuy->GetBuyPrice();
    if(gold < price)
    {
        return false;
    }
    else
    {
        gold -= price;
        return true;
    }
}

void Inventory::Buy(std::vector<Armor*>::iterator armorIt)
{
    if((*armorIt)->IsTradable())
    {
        if(buyItem(*armorIt))
        {
            armors.push_back(*armorIt);
            return;
        }
    }
    else
    {
        // Play a "bip"
    }
}

void Inventory::Buy(std::vector<Weapon*>::iterator weaponIt)
{
    if((*weaponIt)->IsTradable())
    {
        if(buyItem(*weaponIt))
        {
            weapons.push_back(*weaponIt);
            return;
        }
    }
    else
    {
        // Play a "bip"
    }
}

void Inventory::Buy(std::vector<Accessory*>::iterator accessoryIt)
{
    if((*accessoryIt)->IsTradable())
    {
        if(buyItem(*accessoryIt))
        {
            accessories.push_back(*accessoryIt);
            return;
        }
    }
    else
    {
        // Play a "bip"
    }
}

void Inventory::Buy(std::vector<Consumable*>::iterator consumableIt)
{
    if((*consumableIt)->IsTradable())
    {
        if(buyItem(*consumableIt))
        {
            consumables.push_back(*consumableIt);
            return;
        }
    }
    else
    {
        // Play a "bip"
    }
}

void Inventory::Buy(std::vector<Permanent*>::iterator permanentIt)
{
    if((*permanentIt)->IsTradable())
    {
        if(buyItem(*permanentIt))
        {
            permanents.push_back(*permanentIt);
            return;
        }
    }
    else
    {
        // Play a "bip"
    }
}

Weapon* Inventory::GetWeapon()
{
    return weapon;
}

Stats* Inventory::GetAllStatsModifiers()
{
    Stats* allModifiers = new Stats();
    allModifiers->ModifyStats(weapon->GetStats());
    allModifiers->ModifyStats(armor->GetStats());
    allModifiers->ModifyStats(accessory->GetStats());
    return allModifiers;
}


