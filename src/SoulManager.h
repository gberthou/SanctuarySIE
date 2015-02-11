#ifndef SOULMANAGER_H
#define SOULMANAGER_H

#include "Mob.h"
#include "Soul.h"

class SoulManager
{
    public:
        static void Init(void);
		static void Free(void);
		static Soul *GetSoul(MobType type);
    private:
        SoulManager();
        ~SoulManager();
        
		static Soul *souls[MOB_COUNT];
};

#endif // SOULMANAGER_H
