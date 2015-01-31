#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>

class Armor;
class Weapon;
class Accessory;
class Consumable;
class Permanent;
class Item;

class Inventory
{
    public:
        Inventory();
        virtual ~Inventory();
        void AddGold(int amount);
        void Sell(Item* toSell);
    protected:
    private:
        unsigned int gold;
        Armor *armor; // Equipped
        Weapon *weapon; // Equipped
        Accessory *accessory; // Equipped

        std::vector<Armor*> armors;
        std::vector<Weapon*> weapons;
        std::vector<Accessory*> accessories;
        std::vector<Consumable*> consumables;
        std::vector<Permanent*> permanents;
};

#endif // INVENTORY_H
