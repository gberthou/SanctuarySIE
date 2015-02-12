#include "AttackAnimation.h"

AttackAnimation::AttackAnimation(AttackType type1):
	type(type1),
	animation(0)
{
	initAnimation();
}

AttackAnimation::~AttackAnimation()
{
	if(animation != 0)
		delete animation;
}

void AttackAnimation::Start(void)
{
	if(animation != 0)
	{
		animation->Start(0);
	}
}

bool AttackAnimation::HitsEntity(Entity *entity)
{
	return false;
}

sf::Vector2f AttackAnimation::GetCurrentPoint(void) const
{
	unsigned int frame = animation->GetFrame();
	if(frame < actionPoints.size()) // Usual case
		return actionPoints[frame].pos;
	if(actionPoints.size() >= 1)    // Return the first frame (should not happen)
		return actionPoints[0].pos;
	return sf::Vector2f(0, 0);      // Return a meaningless vector (should not happen)
}

void AttackAnimation::initAnimation(void)
{
	ActionPoint inactive;
	ActionPoint tmp(sf::Vector2f(0, 0)); // active

	switch(type)
	{
		case ATTACK_SWORD:
		{
			animation = new Animation(0, 3, 1);
			actionPoints.push_back(inactive);
			
			tmp.pos = sf::Vector2f(5, 0);
			actionPoints.push_back(tmp);

			tmp.pos = sf::Vector2f(10, 0);
			actionPoints.push_back(tmp);
			
			tmp.pos = sf::Vector2f(15, 0);
			actionPoints.push_back(tmp);
			break;
		}

		default:
			break;
	}
}

