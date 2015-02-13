#ifndef LEVEL_H
#define LEVEL_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "Mob.h"
#include "LevelBg.h"
#include "Physics.h"
#include "Character.h"
#include "EntitySoul.h"

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

struct LevelItemDesc
{
	LevelItemDesc(ItemType type1, unsigned int subType, const sf::Vector2f &pos, bool available1 = true):
		available(available1),
		position(pos)
	{
		unsigned int *descPtr = (unsigned int*) &desc;
		desc.type = type1;
		*(descPtr + 1) = subType;
	}

	ItemDesc desc;
	bool available;
	sf::Vector2f position;
};

class Level : public sf::Drawable
{
	public:
		// All the parameters are room-unit
		Level(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
		virtual ~Level();

		void SetBgDesc(const BgDesc &bgDesc);
		void AddMobDesc(const MobDesc *mobDesc);
		void AddItemDesc(const LevelItemDesc *levelItemDesc);
		void SetCollisionMap(const sf::String &filename);
		
		void SpawnEntity(Entity *entity, const sf::Vector2f &position);
		void SpawnItem(const ItemDesc &itemDesc, const sf::Vector2f &position);
		void SpawnSoul(EntitySoul *entity, const sf::Vector2f &position);

		void MakeReady(Character *character);
		void Leave(void);

		void AddDoor(Level *target, unsigned int lx, unsigned int ly, DoorDirection direction);
		
		void Update(unsigned int frameCount);

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        
        void SetPOV(sf::Vector2f);

		unsigned int GetX(void) const;
		unsigned int GetY(void) const;
		unsigned int GetWidth(void) const;
		unsigned int GetHeight(void) const;
		const std::vector<LevelDoor*> &GetDoors(void) const;

	private:
		void checkItems(void);
		void updateSouls(void);
		void checkCharacterAttacks(void);

		// Warning: the following data are room-unit
		unsigned int x;
		unsigned int y;
		unsigned int width;
		unsigned int height;

		BgDesc bgDesc;
		LevelBg *bg;

		std::vector<const MobDesc*> mobDescs;        // Contains the descriptions of all mobs in the level
		std::vector<Mob*> mobs;                      // Mobs that are in the room (when the player is inside)

		std::vector<const LevelItemDesc*> itemDescs; // Contains the descriptions of all items initially in the level (not the dropped ones)
		std::vector<Item*> items;                    // Items inside the room

		std::vector<EntitySoul*> souls;

		sf::String collisionMapFilename;
		CollisionMap collisionMap;

		Character *character;
		Physics *physics;

		// Map display purpose
		std::vector<LevelDoor*> doors;
};

#endif

