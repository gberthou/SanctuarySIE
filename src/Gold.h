#ifndef GOLD_H
#define GOLD_H

#include "PickUpItem.h"
#include "Character.h"

class Gold : public PickUpItem
{
    public:
        Gold(int amount1);
        virtual ~Gold();
        virtual void PickUp(Character *character);
    protected:
    private:
        int amount;
};

#endif // GOLD_H
