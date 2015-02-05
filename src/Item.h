
#ifndef ITEM_H
#define ITEM_H

#include "ItemType.h"
#include "Entity.h"

class Character;

class Item :  public Entity
{
    public:
        Item();
        virtual ~Item();
        virtual void PickUp(Character *character) const = 0;
        void Drop(sf::Vector2f posToDrop);
        ItemType GetType();
    protected:
        ItemType type;
    private:
};


#endif // ITEM_H
