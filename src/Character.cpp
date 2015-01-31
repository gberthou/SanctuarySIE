#include "Character.h"

#include "Weapon.h"
#include "ItemAttribute.h"

Character::Character()
{
    sprite = sf::Sprite(Resources::texCharacter);
    lvl = 1;
    baseStats = new Stats(1,2,3,4,5,6);
    inventory = NULL;
    state = WAIT;
}

Character::~Character()
{
    delete baseStats;
    delete effectiveStats;
    delete inventory;
}

void Character::AddGold(int amount)
{
    inventory->AddGold(amount);
}

void Character::AddMana(int amount)
{
    mp = ((mp + amount) < maxMP) ? ((mp + amount > 0) ? mp + amount : 0) : maxMP;
}

// Attack
// Change state
// Update
// Dealdamage (power, defense)
// hurt

unsigned int Character::getPower()
{
    unsigned int power = 0;
    power = effectiveStats->GetAtt();
    power = (inventory->GetWeapon()->GetEffect() == HALF_DAMAGE) ? power/2 : power;
    return power;
}

unsigned int Character::DealDamage(unsigned int power, Status ownStatus, unsigned int defense, Status enemyStatus)
{
    unsigned int damage = 0;
    damage = (power - defense/2)*(MAX_STAT - defense)/MAX_STAT;
    damage = (enemyStatus == PETRIFIED) ? damage*2 : damage;
    damage = (damage < 1) ? 1 : damage;
    damage = (ownStatus == POISONED) ? 0 : damage;
    return damage;
}
