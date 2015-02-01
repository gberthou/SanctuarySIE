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
    protected:
    private:
};

#endif // PICKUPITEM_H
