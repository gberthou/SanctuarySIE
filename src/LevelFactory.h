#ifndef LEVEL_FACTORY_H
#define LEVEL_FACTORY_H

#include "Level.h"

class LevelFactory
{
	public:
		static Level *CreateLevel(IdLevel idLevel);

	private:
		LevelFactory();
		virtual ~LevelFactory();
};

#endif

