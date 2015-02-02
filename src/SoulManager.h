#ifndef SOULMANAGER_H
#define SOULMANAGER_H

#include "Mob.h"
#include "Soul.h"

class SoulManager
{
    public:
        SoulManager();
        virtual ~SoulManager();
        Soul *GetSoul(MobType type);
    protected:
    private:
        Soul *souls[MOB_COUNT];
};

#endif // SOULMANAGER_H
