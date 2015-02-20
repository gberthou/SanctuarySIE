#include "AttackAnimation.h"

const unsigned int ANIM_FPS = 3;

AttackAnimation::AttackAnimation(AttackType type1):
	Animation(ANIM_FPS),
	type(type1)
{
	initAnimation();
}

AttackAnimation::~AttackAnimation()
{
}

sf::Vector2f AttackAnimation::GetCurrentPoint(void) const
{
	unsigned int frame = GetFrame();

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
			// Set protected attributes
			startFrame = 0;
			endFrame = 3;
			mode = AM_ONCE;
			
			// Set action points
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

