#ifndef BLUESOUL_H
#define BLUESOUL_H

#include <SFML/System.hpp>

#include "Soul.h"
#include "FPSClock.h"

enum BlueSoulBehavior
{
	BSOUL_B_TOGGLE,
	BSOUL_B_HOLD
};

class BlueSoul : public Soul
{
    public:
        BlueSoul(MobType type, BlueSoulBehavior behavior);
		virtual ~BlueSoul();

		void Use(void);
		void StopUsing(void);

		BlueSoulBehavior GetBehavior(void) const;

	private:
		FPSClock clock;
		BlueSoulBehavior behavior;
		bool beingUsed;
};

#endif // BLUESOUL_H
