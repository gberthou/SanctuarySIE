#ifndef REDSOUL_H
#define REDSOUL_H

#include "Soul.h"

class RedSoul : public Soul
{
    public:
        RedSoul(MobType mobType, sf::Int32 cooldown);
        virtual ~RedSoul();

		void Use(void);

		sf::Int32 GetCooldown(void) const;

    protected:
    private:
		void useGiantBat(void);

		sf::Int32 cooldown;
};

#endif // REDSOUL_H
