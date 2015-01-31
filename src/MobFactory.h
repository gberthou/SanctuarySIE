#ifndef MOBFACTORY_H
#define MOBFACTORY_H

#include "Mob.h"

class MobFactory
{
	public:
		static Mob *CreateGiantBat(void);
	private:
		MobFactory();
		virtual ~MobFactory();
};

#endif

