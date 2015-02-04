
#ifndef ITEM_H
#define ITEM_H

#include "Character.h"
#include "ItemType.h"

class Item
{
    public:
        Item();
        virtual ~Item();
        virtual void PickUp(Character *character) const = 0;
        ItemType GetType();
    protected:
        ItemType type;
    private:
};


#endif // ITEM_H
