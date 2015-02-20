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
#include "LevelDoor.h"

//#define DEBUG_CHARACTER_STATE

// ---- CONSTANTS ----
const float HVELOCITY = 4;
const float HVELOCITY_BACKDASH = 8;

const float VVELOCITY = 8;

const sf::Int32 BDASH_TIMEOUT = 200;
const sf::Int32 JUMP_TIMEOUT = 175;
const sf::Int32 JUMP2_TIMEOUT = 75;

// ---- PUBLIC ----

Character::Character(Stats *stats, unsigned int maxHP1, unsigned int maxMP1):
	Fighter(stats, maxHP1, maxMP1),
	attack(0),
	clWalk(60)
{
	AABB hb(sf::Vector2f(30, 50));

    // Redefine this in
    sprite = sf::Sprite(Resources::texCharacter);
    lvl = 1;

	effectiveStats = 0;
    inventory = new Inventory();
    soulSet = new SoulSet();

	stateJump = NOJUMP;
	stateWalk = IDLE;
	stateAttack = NOATTACK;
	stateRedSoul = NORSOUL;
	stateBlueSoul = NOBSOUL;

	SetHitbox(hb, sf::Vector2f(0, 0));	

	computeEffectiveStats(); // Remove me later
}

Character::~Character()
{
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
    computeEffectiveStats();
}

void Character::EarnExp(int amount)
{
    unsigned int xp = exp + amount;
    if(xp >= expToNextLvl)
    {
        xp -= expToNextLvl;
        lvl++;
        expToNextLvl = (unsigned int)(a_EXP*(lvl+1)*(lvl+1) + b_EXP*(lvl+1) + c_EXP);
        LvlUpStats();
    }
}

// #### DAMAGE METHODS ####

bool Character::HitMob(Mob *mob)
{
	sf::Vector2f point;
	if(GetActionPoint(point) && mob->CollidesWith(point))
	{
		unsigned int damage = dealDamage(mob);

		return mob->Hurt(damage);
	}

	return false;
}

// #### STATES METHODS ####


void Character::Attack()
{
	if((stateWalk == IDLE || stateWalk == WALK)  && stateAttack == NOATTACK && stateRedSoul == NORSOUL)
	{
		if(attack != 0)
			delete attack;
		attack = inventory->GetWeapon()->GetAttackAnimation();
		attack->Start(0);

		stateAttack = ATTACK;
		stateWalk = IDLE;
		clAttack.restart();
	}
}

void Character::ReleaseAttack()
{
	if(stateAttack == ATTACK)
		stateAttack = ATTACK_DEACTIVATED;
	else if(stateAttack == ATTACK_TIMEOUT)
		stateAttack = NOATTACK;
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
		if(stateJump == NOJUMP)
		{
			stateWalk = BACKDASH;
			clWalk.restart();
			clBackDashTimeout.restart();
		}
		else // High jump
		{
		}
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

// #### GETTERS ####

Inventory *Character::GetInventory() const
{
	return inventory;
}

SoulSet *Character::GetSoulSet() const
{
	return soulSet;
}

bool Character::GetActionPoint(sf::Vector2f &point) const
{
	if(attack == 0)
		return false;

	point = GetCenter() + attack->GetCurrentPoint();
	return true;
}

bool Character::CollidesWith(const LevelDoor *door) const
{
	return hitbox.CollidesWith(door->GetHitbox());
}

unsigned int Character::GetHP() const
{
	return hp;
}

unsigned int Character::GetMaxHP() const
{
	return maxHP;
}

unsigned int Character::GetMP() const
{
	return mp;
}

unsigned int Character::GetMaxMP() const
{
	return maxMP;
}

unsigned int Character::GetLevel() const
{
	return lvl;
}

unsigned int Character::GetExp() const
{
	return exp;
}

unsigned int Character::GetExpToNextLvl() const
{
	return expToNextLvl;
}

const Stats *Character::GetEffectiveStats() const
{
	return effectiveStats;
}

// #### DEBUG ####
void Character::DrawAttack(sf::RenderTarget &target, sf::RenderStates states) const
{
	if(attack != 0)
	{
		sf::CircleShape circle(5);
		circle.setPosition(GetCenter() + attack->GetCurrentPoint());
		circle.setFillColor(sf::Color(0, 255, 128));

		target.draw(circle, states);
	}
}

// ---- PROTECTED ----

void Character::updateFighter()
{
	updateJump();
	updateWalk();
	updateAttack();
	updateSoul();

#ifdef DEBUG_CHARACTER_STATE
	std::cout << "Attack: " << stateAttack << std::endl;
	std::cout << "Jump  : " << stateJump << std::endl;
	std::cout << "Walk  : " << stateWalk << std::endl;
	std::cout << "RSoul : " << stateRedSoul << std::endl;
	std::cout << "BSoul : " << stateBlueSoul << std::endl;

	std:: cout << std::endl;
#endif
}

unsigned int Character::getPower() const
{
    return effectiveStats->GetAtt();
}

unsigned int Character::dealDamage(const Fighter *other) const
{
    unsigned int damage = 0;
	unsigned int power = getPower();
	unsigned int eDefense = other->GetEffectiveStats()->GetDef();
	Status eStatus = other->GetStatus();

	damage = (power - eDefense/2)*(MAX_STAT - eDefense)/MAX_STAT;
    if(eStatus == PETRIFIED)
		damage *= 2;
	if(damage < 1 || status == POISONED)
		damage = 1;
    return damage;
}

// ---- PRIVATE ----
void Character::computeEffectiveStats()
{
	if(effectiveStats != 0)
		delete effectiveStats;

    effectiveStats = new Stats(*baseStats);
    effectiveStats->ModifyStats(inventory->GetAllStatsModifiers());
}


// #### STATES METHODS ####

void Character::updateJump(void)
{
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
}

void Character::updateWalk(void)
{
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
}

void Character::updateAttack(void)
{
	if(stateAttack == ATTACK || stateAttack == ATTACK_DEACTIVATED)
	{
		attackBehavior();
		if(clAttack.getElapsedTime().asMilliseconds() > inventory->GetWeapon()->GetCooldown()) // Cooldown is over
		{
			if(stateAttack == ATTACK)
				stateAttack = ATTACK_TIMEOUT;
			else // ATTACK_DEACTIVATED
				stateAttack = NOATTACK;
		}
	}
	else
	{
		delete attack;
		attack = 0;
	}
}

void Character::updateSoul(void)
{
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
}
void Character::attackBehavior(void)
{
	if(attack != 0)
	{
		attack->Update();
	}
}

void Character::blueSoulBehavior(void)
{
	BlueSoul *soul = soulSet->GetBlueSoul();
	if(soul != 0)
		soul->Use();
}

std::ostream &operator<<(std::ostream& out, const Character &c)
{
	out.write((char*)&c.lvl,sizeof(c.lvl));
	out.write((char*)&c.exp,sizeof(c.exp));
	out.write((char*)&c.expToNextLvl,sizeof(c.expToNextLvl));
	out<<*c.inventory;
	return out;
}

std::istream &operator>>(std::istream& in, Character &c)
{
	in.read((char*)&c.lvl,sizeof(c.lvl));
	in.read((char*)&c.exp,sizeof(c.exp));
	in.read((char*)&c.expToNextLvl,sizeof(c.expToNextLvl));
	in>>*(c.inventory);
	for(unsigned int i=0;i<c.lvl;++i)
	{
		//c.LvlUpStats();
	}
	return in;
}
