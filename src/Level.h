#ifndef LEVEL_H
#define LEVEL_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "Mob.h"
#include "LevelBg.h"
#include "Physics.h"

class Level;

enum DoorDirection
{
	LEFT,
	UP,
	DOWN,
	RIGHT
};

struct LevelDoor
{
	LevelDoor(Level *target1, unsigned int lx1, unsigned int ly1, DoorDirection dir):
		target(target1),
		lx(lx1),
		ly(ly1),
		direction(dir)
	{
	}

	Level *target;
	unsigned int lx;         // Local X position of the room unit (belongs to [0, w-1])
	unsigned int ly;         // Local Y position of the room unit (belongs to [0, h-1])
	DoorDirection direction; // Door direction (local position in the room unit space)
};

class Level : public sf::Drawable
{
	public:
		Level(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
		virtual ~Level();

		void SetBgDesc(const BgDesc &bgDesc);
		void AddMobDesc(const MobDesc *mobDesc);
		void SetCollisionMap(const sf::String &filename);

		void MakeReady(void);
		void Leave(void);

		void AddDoor(Level *target, unsigned int lx, unsigned int ly, DoorDirection direction);
		
		void Update(void);

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

		unsigned int GetX(void) const;
		unsigned int GetY(void) const;
		unsigned int GetWidth(void) const;
		unsigned int GetHeight(void) const;
		const std::vector<LevelDoor*> &GetDoors(void) const;

	private:
		unsigned int x;
		unsigned int y;
		unsigned int width;
		unsigned int height;

		BgDesc bgDesc;
		LevelBg *bg;

		std::vector<const MobDesc*> mobDescs; // Contains the descriptions of all mobs in the level
		std::vector<Mob*> mobs;               // Mobs that are in the room (when the player is inside)

		sf::String collisionMapFilename;
		CollisionMap collisionMap;

		// Map display purpose
		std::vector<LevelDoor*> doors;
};

#endif

