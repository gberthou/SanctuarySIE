#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <fstream>
#include <map>

#include "Stats.h"

class Armor;
class Weapon;
class Accessory;
class Consumable;
class Permanent;
class Tradable;
class Item;

class Inventory
{
    public:
        Inventory();
        virtual ~Inventory();
        void AddGold(int amount);
        
        void Sell(std::vector<Armor*>::iterator armorIt);
        void Sell(std::vector<Weapon*>::iterator weaponIt);
        void Sell(std::vector<Accessory*>::iterator accessoryIt);
        void Sell(std::vector<Consumable*>::iterator consumableIt);
        
        void Buy(std::vector<Armor*>::iterator armorIt);
        void Buy(std::vector<Weapon*>::iterator weaponIt);
        void Buy(std::vector<Accessory*>::iterator accessoryIt);
        void Buy(std::vector<Consumable*>::iterator consumableIt);
        void Buy(std::vector<Permanent*>::iterator permanentIt);
        
        void LootItem(Item *item);
        
        Stats* GetAllStatsModifiers() const;
        
        void EquipWeapon(std::vector<Weapon*>::const_iterator it);
        Weapon* GetWeapon() const;
        const std::vector<Weapon*> &GetWeapons() const;

    protected:
    private:
        void sellItem(Tradable* toSell);
        bool buyItem(Tradable* toBuy);
        
        unsigned int gold;
        Armor *armor;           // Equipped
        Weapon *weapon;         // Equipped
        Accessory *accessory;   // Equipped
        
        std::vector<Armor*> armors;
        std::vector<Weapon*> weapons;
        std::vector<Accessory*> accessories;
        std::vector<Consumable*> consumables;
        std::vector<Permanent*> permanents;
        
        friend std::ostream &operator<<(std::ostream& output, const Inventory &inv);
        friend std::istream &operator>>(std::istream& input, Inventory &inv);
        
        template <class T>
        friend std::ostream & serializeStuff(std::ostream& out, const std::vector<T*> &inv)
        {
            unsigned int sizeVec = inv.size();
            
            std::map<int, int> inventoryMap;
            for(unsigned int i=0;i<inv.size();++i)
            {
                if(!inv[i])
                {
                    --sizeVec;
                    continue;
                }
                if(!inv[i]->HasEnchantment())
                {
                    inventoryMap[inv[i]->GetSubtype().id]++;
                }
            }
            out.write((char*)&sizeVec,sizeof(sizeVec));
            for(std::map<int, int>::iterator it=inventoryMap.begin();
                    it!=inventoryMap.end();
                    ++it)
            {
                out.write((char*)&(it->first),sizeof(it->first));
                out.write((char*)&(it->second),sizeof(it->second));
            }
            return out;
        }
        
        template <class T>
        friend std::ostream & serializeItem(std::ostream& out, const std::vector<T*> &inv)
        {
            unsigned int sizeVec = inv.size();
            
            std::map<int, int> inventoryMap;
            for(unsigned int i=0;i<inv.size();++i)
            {
                if(!inv[i])
                {
                    --sizeVec;
                    continue;
                }
                inventoryMap[inv[i]->GetSubtype().id]++;
                
            }
            out.write((char*)&sizeVec,sizeof(sizeVec));
            for(std::map<int, int>::iterator it=inventoryMap.begin();
                    it!=inventoryMap.end();
                    ++it)
            {
                out.write((char*)&(it->first),sizeof(it->first));
                out.write((char*)&(it->second),sizeof(it->second));
            }
            return out;
        }
    
};

#endif // INVENTORY_H
