#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>

class Armor;
class Weapon;
class Accessory;
class Consumable;
class Permanent;
class Tradable;

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

        Weapon* GetWeapon();
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
};

#endif // INVENTORY_H
