#include <iostream>

#include "Character.h"
#include "Weapon.h"
#include "ItemAttribute.h"
#include "Gameplay.h"
#include "Mob.h"
#include "Item.h"
#include "RedSoul.h"
#include "BlueSoul.h"
#include "YellowSoul.h"

//#define DEBUG_CHARACTER_STATE

// ---- CONSTANTS ----
const float HVELOCITY = 4;
const float HVELOCITY_BACKDASH = 8;

const float VVELOCITY = 8;

const sf::Int32 BDASH_TIMEOUT = 200;
const sf::Int32 JUMP_TIMEOUT = 175;
const sf::Int32 JUMP2_TIMEOUT = 75;

// ---- PUBLIC ----

Character::Character():
	Entity(),
	clWalk(60)
{
	AABB hb(sf::Vector2f(30, 50));

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

	SetHitbox(hb, sf::Vector2f(0, 0));	
}

Character::~Character()
{
    delete baseStats;
    delete effectiveStats;
    delete inventory;
}

// #### PICKUP ITEMS METHODS ####

void Character::AddGold(int amount)
{
    inventory->AddGold(amount);
}

void Character::AddMana(int amount)
{
    mp = ((mp + amount) < maxMP) ? ((mp + amount > 0) ? mp + amount : 0) : maxMP;
}

// #### XP METHODS ####

// Redefine One for each character
void Character::LvlUpStats()
{
    baseStats->ModifyStats(new Stats(1,(lvl %2 != 0) ? 1 : 0,1,1,1,1));
    maxHP += 12;
    maxMP = (unsigned int)(a_MANA*lvl*lvl + b_MANA*lvl + c_MANA);
    updateStats();
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

// #### DAMAGE METHODS ####

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

// #### STATES METHODS ####


void Character::Attack()
{
	if((stateWalk == IDLE || stateWalk == WALK)  && stateRedSoul == NORSOUL)
	{
		stateAttack = ATTACK;
		stateWalk = IDLE;
		clAttack.restart();
	}
}

void Character::Jump()
{
	if((stateWalk == IDLE || stateWalk == WALK) && stateAttack == NOATTACK && stateRedSoul == NORSOUL)
	{
		if(stateJump == NOJUMP) // -> Simple jump
		{
			stateJump = JUMP;
			clJumpTimeout.restart();
		}
		else if(stateJump == FALL_DEACTIVATED) // -> Double jump
		{
			stateJump = JUMP2;
			SetVelocityY(0);
			clJumpTimeout.restart();
		}	
	}
}

void Character::ReleaseJump()
{
	switch(stateJump)
	{
		case JUMP:
			stateJump = JUMP_DEACTIVATED;
			break;

		case FALL:
			stateJump = FALL_DEACTIVATED;
			break;

		case JUMP2:
			stateJump = JUMP2_DEACTIVATED;
			break;

		case FALL2:
			stateJump = FALL2_DEACTIVATED;
			break;

		case FALL_WAIT_DEACTIVATION:
			stateJump = NOJUMP;
			break;

		default:
			break;
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

void Character::BackDash()
{
	if(stateAttack == NOATTACK && (stateWalk == IDLE || stateWalk == WALK)  && stateRedSoul == NORSOUL)
	{
		stateWalk = BACKDASH;
		clWalk.restart();
		clBackDashTimeout.restart();
	}
	
}

void Character::ReleaseBackDash()
{
	if(stateWalk == BACKDASH)
		stateWalk = BACKDASH_DEACTIVATED;
	else if(stateWalk == BACKDASH_TIMEOUT)
		stateWalk = IDLE;
}

void Character::StopWalking(Orientation orientation1)
{
	if(stateWalk == WALK && orientation == orientation1) // Do not stop walking if it's not the right direction
		stateWalk = IDLE;
}

void Character::UseRedSoul()
{
	RedSoul *soul = soulSet->GetRedSoul();
	if(soul == 0)
		return;

	if((stateWalk == IDLE || stateWalk == WALK) && stateAttack == NOATTACK && stateRedSoul == NORSOUL)
	{
		stateRedSoul = RSOUL;
		clRedSoul.restart();

		soul->Use();
	}
}

void Character::UseBlueSoul()
{
	BlueSoul *soul = soulSet->GetBlueSoul();
	if(soul == 0)
		return;
	
	if(stateBlueSoul == NOBSOUL)
	{
		if(soul->GetBehavior() == BSOUL_B_HOLD)
		{
			stateBlueSoul = BSOUL_HELD;
		}
		else
		{
			stateBlueSoul = BSOUL_ACTIVATING;
		}

	}
	else if(stateBlueSoul == BSOUL_ACTIVATED)
		stateBlueSoul = BSOUL_DEACTIVATING;
}

void Character::ReleaseBlueSoul()
{
	if(stateBlueSoul == BSOUL_ACTIVATING)
		stateBlueSoul = BSOUL_ACTIVATED;
	else if(stateBlueSoul == BSOUL_HELD || stateBlueSoul == BSOUL_DEACTIVATING)
		stateBlueSoul = NOBSOUL;
}

void Character::UpdateStates()
{
	if(stateAttack == ATTACK)
	{
		attackBehavior();
		if(clAttack.getElapsedTime().asMilliseconds() > inventory->GetWeapon()->GetCooldown()) // Cooldown is over
			stateAttack = NOATTACK;
	}

	if(stateJump == JUMP || stateJump == JUMP_DEACTIVATED || stateJump == JUMP2 || stateJump == JUMP2_DEACTIVATED)
	{
		AddPosition(sf::Vector2f(0, -VVELOCITY));
		if(clJumpTimeout.getElapsedTime().asMilliseconds() > JUMP_TIMEOUT)
		{
			if(stateJump == JUMP)
				stateJump = FALL;
			else if(stateJump == JUMP_DEACTIVATED)
				stateJump = FALL_DEACTIVATED;
		}

		if(clJumpTimeout.getElapsedTime().asMilliseconds() > JUMP2_TIMEOUT)
		{
			if(stateJump == JUMP2)
				stateJump = FALL2;
			else if(stateJump == JUMP2_DEACTIVATED)
				stateJump = FALL2_DEACTIVATED;	
		}
	}

	if(onGround)
	{
		if(stateJump == FALL_DEACTIVATED || stateJump == FALL2_DEACTIVATED)
		{
			stateJump = NOJUMP;
		}
		else if(stateJump == FALL || stateJump == FALL2)
		{
			stateJump = FALL_WAIT_DEACTIVATION;
		}
	}
	else if((stateWalk == IDLE || stateWalk == WALK) && stateJump == NOJUMP)
		stateJump = FALL_DEACTIVATED;

	if(stateWalk == WALK)
	{
		unsigned int frameCount = clWalk.GetElapsedFrames();
		if(frameCount > 0)
		{
			clWalk.restart();
		
			AddPosition(sf::Vector2f((orientation == ORIENTATION_LEFT ? -HVELOCITY : HVELOCITY) * frameCount, 0));	
		}
	}
	else if(stateWalk == BACKDASH || stateWalk == BACKDASH_DEACTIVATED)
	{
		unsigned int frameCount = clWalk.GetElapsedFrames();
		if(frameCount > 0)
		{
			clWalk.restart();
			
			AddPosition(sf::Vector2f((orientation != ORIENTATION_LEFT ? -HVELOCITY_BACKDASH : HVELOCITY_BACKDASH) * frameCount, 0));
		}
	
		if(clBackDashTimeout.getElapsedTime().asMilliseconds() > BDASH_TIMEOUT)
		{
			if(stateWalk == BACKDASH)
				stateWalk = BACKDASH_TIMEOUT;
			else if(stateWalk == BACKDASH_DEACTIVATED)
				stateWalk = IDLE;
		}
	}

	if(stateRedSoul == RSOUL)
	{
		if(clRedSoul.getElapsedTime().asMilliseconds() > soulSet->GetRedSoul()->GetCooldown()) // Cooldown is over
		   stateRedSoul = NORSOUL;	
	}

	if(stateBlueSoul != NOBSOUL)
	{
		blueSoulBehavior();

		// TODO : stop blue soul of there is no more mana
	}

#ifdef DEBUG_CHARACTER_STATE
	std::cout << "Attack: " << stateAttack << std::endl;
	std::cout << "Jump  : " << stateJump << std::endl;
	std::cout << "Walk  : " << stateWalk << std::endl;
	std::cout << "RSoul : " << stateRedSoul << std::endl;
	std::cout << "BSoul : " << stateBlueSoul << std::endl;

	std:: cout << std::endl;
#endif
}

// #### GETTERS ####

Inventory *Character::GetInventory() const
{
	return inventory;
}

SoulSet *Character::GetSoulSet() const
{
	return soulSet;
}

// ---- PRIVATE ----

// #### DAMAGE METHODS ####

unsigned int Character::getPower()
{
    unsigned int power = 0;
    power = effectiveStats->GetAtt();
    return power;
}

void Character::updateStats()
{
    effectiveStats = baseStats;
    effectiveStats->ModifyStats(inventory->GetAllStatsModifiers());
}

unsigned int Character::dealDamage(unsigned int power, Status ownStatus, unsigned int defense, Status enemyStatus)
{
    unsigned int damage = 0;
    damage = (power - defense/2)*(MAX_STAT - defense)/MAX_STAT;
    damage = (enemyStatus == PETRIFIED) ? damage*2 : damage;
    damage = (damage < 1 || ownStatus == POISONED) ? 1 : damage;
    return damage;
}

// #### STATES METHODS ####

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

void Character::blueSoulBehavior(void)
{
	BlueSoul *soul = soulSet->GetBlueSoul();
	if(soul != 0)
		soul->Use();
}

