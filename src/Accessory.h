#ifndef ACCESSORY_H
#define ACCESSORY_H

#include "Item.h"
#include "Stats.h"

class Accessory : public Item
{
    public:
        Accessory(Stats *stats1);
        virtual ~Accessory();
    protected:
    private:
};

#endif // ACCESSORY_H
