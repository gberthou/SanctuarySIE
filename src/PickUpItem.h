#ifndef PICKUPITEM_H
#define PICKUPITEM_H

#include <SFML/System.hpp>

#include "Item.h"
#include "Character.h"

class PickUpItem : public Item
{
    public:
        PickUpItem();
        virtual ~PickUpItem();
        virtual void PickUp() const = 0;
    protected:
    private:
};

#endif // PICKUPITEM_H
