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

enum IdLevel
{
	CORRIDOR0,
	CORRIDOR1,
	CORRIDOR2,
	CORRIDOR3,

	LEVEL_NUMBER
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

class LevelDoor;

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

		void AddDoor(LevelDoor *door);
		
		void Update(unsigned int frameCount);

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        
        void SetPOV(sf::Vector2f);

		// Returns whether or not the player goes through a door.
		// id : reference to the variable that will contain the id of the room the player is
		// going to.
		// deltaPosition : difference between the two doors positions.
		bool ChangeLevelRequired(IdLevel &id, sf::Vector2f &deltaPosition) const;

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

