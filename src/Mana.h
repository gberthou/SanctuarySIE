#ifndef MANA_H
#define MANA_H

#include "PickUpItem.h"
#include "Character.h"


class Mana : public PickUpItem
{
    public:
        Mana(int amount1);
        virtual ~Mana();
        virtual void PickUp(Character *character);
    protected:
    private:
        int amount;
};

#endif // MANA_H
