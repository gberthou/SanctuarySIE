#include "Gold.h"

Gold::Gold(int amount1)
{
    amount = amount1;
}

Gold::~Gold()
{
    //dtor
}

void Gold::PickUp(Character *character)
{
    character->AddGold(amount);
}
