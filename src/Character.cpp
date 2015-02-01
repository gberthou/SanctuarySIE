#include "Character.h"
#include "Weapon.h"
#include "ItemAttribute.h"
#include "Gameplay.h"

Character::Character()
{
    sprite = sf::Sprite(Resources::texCharacter);
    lvl = 1;
    baseStats = new Stats(10,6,10,12,11,9);
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

void Character::EarnExp(int amount)
{
    unsigned int xp = exp + amount;
    if(xp > expToNextLvl)
    {
        xp -= expToNextLvl;
        lvl++;
        expToNextLvl = (unsigned int)(a_EXP*(lvl+1)*(lvl+1) + b_EXP*(lvl+1) + c_EXP);
        LvlUpStats();
    }
}

// Redefine One for each character
void Character::LvlUpStats()
{
    baseStats->ModifyStats(new Stats(1,(lvl %2 != 0) ? 1 : 0,1,1,1,1));
    maxHP += 12;
    maxMP = (unsigned int)(a_MANA*(lvl+1)*(lvl+1) + b_MANA*(lvl+1) + c_MANA);
    updateStats();
}


void Character::updateStats()
{
    effectiveStats = baseStats;
    effectiveStats->ModifyStats(inventory->GetAllStatsModifiers());
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
    return power;
}

bool Character::Hurt(unsigned int damage)
{
    if(hp - damage <= 0)
    {
        hp = 0;
        return true;
    }
    else
    {
        hp -= damage;
        return false;
    }
}

unsigned int Character::DealDamage(unsigned int power, Status ownStatus, unsigned int defense, Status enemyStatus)
{
    unsigned int damage = 0;
    damage = (power - defense/2)*(MAX_STAT - defense)/MAX_STAT;
    damage = (enemyStatus == PETRIFIED) ? damage*2 : damage;
    damage = (damage < 1 || ownStatus == POISONED) ? 1 : damage;
    return damage;
}

 void Character::Walk(sf::Vector2f direction)
 {
     pos += (direction*2.f*DT);
 }
