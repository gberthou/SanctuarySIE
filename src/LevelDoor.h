#ifndef LEVELDOOR_H
#define LEVELDOOR_H

#include "AABB.h"
#include "Level.h"
#include "Entity.h"

enum DoorDirection
{
	LEFT,
	UP,
	DOWN,
	RIGHT
};

class LevelDoor
{
	public:
		LevelDoor(IdLevel idLevel, const AABB &hitbox, unsigned int lx, unsigned int ly, DoorDirection dir);
		virtual ~LevelDoor();

		void SetTarget(const LevelDoor *target);

		bool CollidesWith(const Entity *entity) const;

		IdLevel GetIdLevel(void) const;
		const LevelDoor *GetTarget(void) const;
		const AABB &GetHitbox(void) const;
		unsigned int GetLocalX(void) const;
		unsigned int GetLocalY(void) const;
		DoorDirection GetDirection(void) const;
		sf::Vector2f GetSymmetricalPoint(const Entity *entity) const;

	private:
		IdLevel idLevel;
		const LevelDoor *target;
		AABB hitbox;
	
		// Map display purpose
		unsigned int lx;         // Local X position of the	room unit (belongs to [0, w-1])
		unsigned int ly;         // Local Y position of the room unit (belongs to [0, h-1])
		DoorDirection direction; // Door direction (local position in the room unit space)
};

#endif

