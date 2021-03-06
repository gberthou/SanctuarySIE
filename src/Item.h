
#ifndef ITEM_H
#define ITEM_H

#include "ItemType.h"
#include "Entity.h"

class Character;

class Item : public Entity
{
    public:
        Item();
        virtual ~Item();
        virtual void PickUp(Character *character) = 0;

        ItemType GetType();
        virtual ItemSubtype GetSubtype() const = 0;
        
    protected:
        ItemType type;
        
    private:
};


#endif // ITEM_H
