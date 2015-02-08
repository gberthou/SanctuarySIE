#ifndef PICKUP_H
#define PICKUP_H

#include <SFML/System.hpp>

#include "Item.h"
#include "Character.h"

class PickUp : public Item
{
    public:
        PickUp();
        virtual ~PickUp();
    protected:
    private:
};

#endif // PICKUP_H
