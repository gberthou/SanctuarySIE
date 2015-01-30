
#ifndef ITEM_H
#define ITEM_H

#include "Character.h"

class Item
{
    public:
        Item();
        virtual ~Item();
        virtual void PickUp(Character *character) const = 0;
    protected:

    private:
};


#endif // ITEM_H
