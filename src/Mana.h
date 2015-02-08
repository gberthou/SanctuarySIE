#ifndef MANA_H
#define MANA_H

#include "PickUp.h"
#include "Character.h"


class Mana : public PickUp
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
