#ifndef LEVEL_H
#define LEVEL_H

#include <vector>

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
	unsigned int lx;         // local X position of the room unit (belongs to [0, w-1])
	unsigned int ly;         // local Y position of the room unit (belongs to [0, h-1])
	DoorDirection direction; // door direction (local position in the room unit space)
};

class Level
{
	public:
		Level(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
		virtual ~Level();

		void AddDoor(Level *target, unsigned int lx, unsigned int ly, DoorDirection direction);

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

		// Map display purpose
		std::vector<LevelDoor*> doors;
};

#endif

