#ifndef LEVEL_FACTORY_H
#define LEVEL_FACTORY_H

#include "Level.h"

enum TypeLevel
{
	LEVEL_CORRIDOR,

	LEVEL_NUMBER
};

class LevelFactory
{
	public:
		static Level *CreateLevel(TypeLevel typeLevel);

	private:
		LevelFactory();
		virtual ~LevelFactory();
};

#endif

