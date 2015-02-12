#ifndef ATTACKANIMATION_H
#define ATTACKANIMATION_H

#include <vector>

#include "Animation.h"
#include "Entity.h"

enum AttackType
{
	ATTACK_SWORD,
	ATTACK_HEAVY,
	ATTACK_SPEAR
};

struct ActionPoint
{
	ActionPoint():
		active(false)
	{
	}

	ActionPoint(const sf::Vector2f &p):
		pos(p),
		active(true)
	{
	}

	sf::Vector2f pos; // Offset, always right-oriented, from the center of the character
	bool active;
};

class AttackAnimation
{
	public:
		AttackAnimation(AttackType type);
		virtual ~AttackAnimation();

		void Start(void);
		bool HitsEntity(Entity *entity);

		sf::Vector2f GetCurrentPoint(void) const;
	private:
		void initAnimation(void);

		AttackType type;
		Animation *animation;
		std::vector<ActionPoint> actionPoints;
};

#endif

