#include <iostream>

#include "Character.h"
#include "Weapon.h"
#include "ItemAttribute.h"
#include "Gameplay.h"
#include "Mob.h"
#include "Item.h"

const float HVELOCITY = 4;

const sf::Int32 JUMP_COOLDOWN = 500;
const sf::Int32 JUMP_TIMEOUT = 200;

Character::Character():
	Entity(),
	clWalk(60)
{
    // Redefine this in
    sprite = sf::Sprite(Resources::texCharacter);
    lvl = 1;
    baseStats = new Stats(10,6,10,12,11,9);
    maxHP = 320;
    hp = maxHP;
    maxMP = (unsigned int)(a_EXP + b_EXP + c_EXP);
    mp = maxMP;

	effectiveStats = 0;
    inventory = new Inventory();
    soulSet = new SoulSet();

	stateJump = NOJUMP;
	stateWalk = IDLE;
	stateAttack = NOATTACK;
	stateRedSoul = NORSOUL;
	stateBlueSoul = NOBSOUL;
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
    maxMP = (unsigned int)(a_MANA*lvl*lvl + b_MANA*lvl + c_MANA);
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

unsigned int Character::dealDamage(unsigned int power, Status ownStatus, unsigned int defense, Status enemyStatus)
{
    unsigned int damage = 0;
    damage = (power - defense/2)*(MAX_STAT - defense)/MAX_STAT;
    damage = (enemyStatus == PETRIFIED) ? damage*2 : damage;
    damage = (damage < 1 || ownStatus == POISONED) ? 1 : damage;
    return damage;
}

void Character::Attack()
{
	if(stateWalk != BACKDASH && stateRedSoul == NORSOUL)
	{
		stateAttack = ATTACK;
		clAttack.restart();
	}
}

void Character::Jump()
{
	if(stateWalk != BACKDASH && stateAttack == NOATTACK && stateRedSoul == NORSOUL)
	{
		if(stateJump == NOJUMP) // -> Jump
		{
			stateJump = JUMP;
			clJump.restart();
			clJumpTimeout.restart();
		}
		else if((stateJump == JUMP && clJump.getElapsedTime().asMilliseconds() > JUMP_COOLDOWN) || stateJump == FALL) // -> Jump2
		{
			stateJump = JUMP2;
		}	
	}
}

void Character::Walk(Orientation orientation1)
{
	if(stateAttack == NOATTACK && stateWalk == IDLE && stateRedSoul == NORSOUL)
	{
		orientation = orientation1;
		stateWalk = WALK;
		clWalk.restart();
	}
}

void Character::StopWalking(Orientation orientation1)
{
	if(orientation == orientation1) // Do not stop walking if it's not the right direction
		stateWalk = IDLE;
}

void Character::UpdateStates()
{
	if(stateAttack == ATTACK)
	{
		attackBehavior();
		if(clAttack.getElapsedTime().asMilliseconds() > inventory->GetWeapon()->GetCooldown()) // Cooldown is over
			stateAttack = NOATTACK;
	}

	if(stateJump == JUMP || stateJump == JUMP2)
	{
		AddAcceleration(sf::Vector2f(0, -100));
		if(clJumpTimeout.getElapsedTime().asMilliseconds() > JUMP_TIMEOUT)
			stateJump = (stateJump == JUMP ? FALL : FALL2);
	}

	if(stateWalk == WALK)
	{
		unsigned int frameCount = clWalk.GetElapsedFrames();
		if(frameCount > 0)
		{
			clWalk.restart();
			
			pos.x += (orientation == ORIENTATION_LEFT ? -HVELOCITY * frameCount : HVELOCITY * frameCount);
		}
	}

	std::cout << "Attack: " << stateAttack << std::endl;
	std::cout << "Jump: " << stateJump << std::endl;
	std::cout << "Walk: " << stateWalk << std::endl;

	std:: cout << std::endl;
}

Inventory *Character::GetInventory() const
{
	return inventory;
}

void Character::attackBehavior(void)
{
    // Collision -> get mob

	/*
    Mob* mob = new Mob();
    updateStats();
    unsigned int dmg = dealDamage(getPower(), status, mob->GetStats()->GetDef(), mob->GetStatus());
    if(mob->Hurt(dmg))
    {
        // Mob is dead
        mob->LootMob((unsigned int)effectiveStats->GetLck());
        EarnExp(mob->GiveXP());
    }
	*/
}

