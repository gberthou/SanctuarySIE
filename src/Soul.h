#ifndef SOUL_H
#define SOUL_H

#include "Mob.h"
#include "SoulTypes.h"

class Soul
{
    public:
        Soul(MobType mobType, SoulType soulType);
        virtual ~Soul();

		MobType GetType(void) const;
		SoulType GetSoulType(void) const;

	protected:
		MobType type;
		SoulType soulType;

	private:

};

#endif // SOUL_H

