#include "Character.h"

Character::Character()
{
    sprite = sf::Sprite(Resources::texCharacter);
    lvl = 1;
    status = NULL;
    stats = new Stats(1,2,3,4,5,6);
    inventory = NULL;
    state = WAIT;
}

Character::~Character()
{
    delete status;
    delete stats;
    delete inventory;
}

void Character::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::Sprite chara = sf::Sprite(sprite);

    chara.setPosition(128,128);

    target.draw(chara,states);
}

void Character::AddGold(int amount)
{
    inventory->AddGold(amount);
}

void Character::AddMana(int amount)
{
    mp = ((mp + amount) < maxMP) ? ((mp + amount > 0) ? mp + amount : 0) : maxMP;
}
