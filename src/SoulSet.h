#ifndef SOULSET_H
#define SOULSET_H

#include <vector>

#include "Mob.h"

class SoulManager;
class RedSoul;
class BlueSoul;
class YellowSoul;

class SoulSet
{
    public:
        SoulSet();
        virtual ~SoulSet();

		void AddSoul(MobType type);

		// Red soul
		void EquipRedSoul(std::vector<RedSoul*>::const_iterator it);
        RedSoul *GetRedSoul() const;
		const std::vector<RedSoul*> &GetRedSouls() const;

		// Blue soul
        void EquipBlueSoul(std::vector<BlueSoul*>::const_iterator it);
		BlueSoul *GetBlueSoul() const;
		const std::vector<BlueSoul*> &GetBlueSouls() const;
        
		// Yellow soul
		YellowSoul *GetYellowSoul() const;
    
	private:
		void addRedSoul(RedSoul *soul);
		void addBlueSoul(BlueSoul *soul);
    
        RedSoul *redSoul;       // Equipped
        BlueSoul *blueSoul;     // Equipped
        YellowSoul *yellowSoul; // Equipped
    
        std::vector<RedSoul*> redSouls;
        std::vector<BlueSoul*> blueSouls;
        std::vector<YellowSoul*> yellowSouls;
};

#endif // SOULSET_H
