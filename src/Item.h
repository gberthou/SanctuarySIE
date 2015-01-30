
#ifndef ITEM_H
#define ITEM_H

#include "Stats.h"

class Item
{
    public:
        Item(Stats *stats1);
        virtual ~Item();
    protected:
        Stats *stats;
    private:



};


#endif // ITEM_H
