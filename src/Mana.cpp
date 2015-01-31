#include "Mana.h"

Mana::Mana(int amount1)
{
    amount = amount1;
}

Mana::~Mana()
{
    //dtor
}

void Mana::PickUp(Character *character)
{
    character->AddMana(amount);
}
