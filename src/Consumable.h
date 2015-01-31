#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "Tradable.h"


class Consumable : public Tradable
{
    public:
        Consumable(sf::String name1, sf::String description1, bool trade1, unsigned int sellPrice1, unsigned int buyPrice1);
        virtual ~Consumable();
    protected:
    private:
};

#endif // CONSUMABLE_H
