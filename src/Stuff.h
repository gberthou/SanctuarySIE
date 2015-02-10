#ifndef STUFF_H
#define STUFF_H

#include <set>

#include "Stats.h"
#include "ItemAttribute.h"
#include "Tradable.h"
#include "Character.h"
#include "Enchantment.h"

class Stuff : public Tradable
{
    public:
        Stuff(Stats *stats1, sf::String name1, sf::String description1, bool trade1, unsigned int sellPrice1, unsigned int buyPrice1);
        virtual ~Stuff();
        void AddAttribute(ItemAttribute attribute1);
        virtual void PickUp(Character *character);
        ItemEffect GetEffect() const;
        Stats* GetStats() const;
		bool HasEnchantment() const;
    protected:
        Stats *stats;
        ItemEffect effect;
        std::set<ItemAttribute> attributes;
		Enchantment *enchantment;
    private:
};

#endif // STUFF_H
