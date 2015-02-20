#ifndef LEVEL_FACTORY_H
#define LEVEL_FACTORY_H

#include <map>

#include "Level.h"

class LevelFactory
{
	public:
		static Level *CreateLevel(IdLevel idLevel);

		static void CreateDoors(void);
		static void FreeDoors(void);

	private:
		LevelFactory();
		virtual ~LevelFactory();

		static LevelDoor *getDoor(IdLevel idLevel, unsigned int idDoor);
		static void associateDoors(IdLevel idLevel1, unsigned int idDoor1, IdLevel idLevel2, unsigned int idDoor2);
		
		static std::map<unsigned int, LevelDoor*> doors;
};

#endif

