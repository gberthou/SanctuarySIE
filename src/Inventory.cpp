#include <iostream>

#include "Inventory.h"
#include "Armor.h"
#include "Weapon.h"
#include "Accessory.h"
#include "Consumable.h"
#include "Permanent.h"
#include "Tradable.h"
#include "ItemFactory.h"

#define DEBUG_INVENTORY

// ---- PUBLIC ----

Inventory::Inventory()
{
    //ctor
    weapon = 0;
    armor = 0;
    accessory = 0;
}

Inventory::~Inventory()
{
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

// #### GOLD METHODS ####

void Inventory::AddGold(int amount)
{
    gold += amount;
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

// #### BUY METHODS ####

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

// #### LOOT METHODS ####

void Inventory::LootItem(Item *item)
{
    switch(item->GetType())
    {
        case ARMOR:
            armors.push_back((Armor*)item);
            break;
        case WEAPON:
            weapons.push_back((Weapon*)item);
            break;
        case ACCESSORY:
            accessories.push_back((Accessory*)item);
            break;
        /*
		case CONSUMABLE:
            consumables.push_back((Consumable*)item);
            break;
        case PERMANENT:
            permanents.push_back((Permanent*)item);
            break;
        */

		default:
            break;
    }

#ifdef DEBUG_INVENTORY
	std::cout << "Weapons    : " << weapons.size() << std::endl;
	std::cout << "Armors     : " << armors.size() << std::endl;
	std::cout << "Accessories: " << accessories.size() << std::endl;
	
	std::cout << std::endl;
#endif
}

// #### STATS METHODS ####

Stats* Inventory::GetAllStatsModifiers() const
{
    Stats* allModifiers = new Stats();
    
	if(weapon != 0)
		allModifiers->ModifyStats(weapon->GetStats());
    
	if(armor != 0)
		allModifiers->ModifyStats(armor->GetStats());
    
	if(accessory != 0)
		allModifiers->ModifyStats(accessory->GetStats());
    return allModifiers;
}

// #### SETTERS ####

void Inventory::EquipWeapon(std::vector<Weapon*>::const_iterator it)
{
	weapon = *it;
}

// #### GETTERS ####

Weapon* Inventory::GetWeapon() const
{
    return weapon;
}

const std::vector<Weapon*> &Inventory::GetWeapons() const
{
	return weapons;
}

// ---- PRIVATE ----

void Inventory::sellItem(Tradable *toSell)
{
    unsigned int price = toSell->GetSellPrice();
    gold += price;
	delete toSell;
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

std::ostream &operator<<(std::ostream& out, const Inventory &inv)
{
    out.write((char*)&inv.gold,sizeof(inv.gold));
    serializeStuff(out,inv.armors);
    serializeStuff(out,inv.weapons);
    serializeStuff(out,inv.accessories);
    serializeItem(out,inv.consumables);
    serializeItem(out,inv.permanents);
    
    return out;
}
 
std::istream &operator>>(std::istream& in, Inventory &inv)
{
    in.read((char*)&inv.gold,sizeof(inv.gold));
    
    unsigned int sizeVec;
    
    for(int itemType=0;itemType<3;++itemType)
    {
        in.read((char*)&sizeVec,sizeof(sizeVec));

        switch(itemType)
        {
            case 0:
                inv.armors.resize(sizeVec);
                break;
            case 1:
                inv.weapons.resize(sizeVec);
                break;
            case 2:
                inv.accessories.resize(sizeVec);
                break;
            case 3:
                inv.consumables.resize(sizeVec);
                break;
            case 4:
                inv.permanents.resize(sizeVec);
                break;
            default :
                break;
        }
       
        for(unsigned int i=0;i<sizeVec;++i)
        {
            int id;
            int nb;
            in.read((char*)&id,sizeof(id));
            in.read((char*)&nb,sizeof(nb));
            for(; nb>0; --nb)
            {
                in.read((char*)&nb,sizeof(nb));
                ItemSubtype itemsubtype = {id};
                switch(itemType)
                {
                    case 0:
                        inv.armors.push_back(ItemFactory::CreateArmor(itemsubtype.armor));
                        break;
                    case 1:
                        inv.weapons.push_back(ItemFactory::CreateWeapon(itemsubtype.weapon));
                        break;
                    case 2:
                        inv.accessories.push_back(ItemFactory::CreateAccessory(itemsubtype.accessory));
                        break;
                    case 3:
                        inv.consumables.push_back(ItemFactory::CreateConsumable(itemsubtype.consumable));
                        break;
                    case 4:
                        inv.permanents.push_back(ItemFactory::CreatePermanent(itemsubtype.permanent));
                        break;
                    default :
                        break;
                }
            }
        }
        if(itemType<3)
        {
            // TODO : manage enchantment 
        }
        
    }
    
    
    return in;
}



