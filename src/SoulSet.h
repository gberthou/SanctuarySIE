#ifndef SOULSET_H
#define SOULSET_H

#include <vector>

class SoulManager;
class RedSoul;
class BlueSoul;
class YellowSoul;

class SoulSet
{
    public:
        SoulSet();
        virtual ~SoulSet();
        RedSoul *GetRedSoul();
        BlueSoul *GetBlueSoul();
        YellowSoul *GetYellowSoul();
    protected:
    private:
    
        RedSoul *redSoul;       // Equipped
        BlueSoul *blueSoul;     // Equipped
        YellowSoul *yellowSoul; // Equipped
    
        std::vector<RedSoul*> redSouls;
        std::vector<BlueSoul*> blueSouls;
        std::vector<YellowSoul*> yellowSouls;
        
        SoulManager *soulManager;
};

#endif // SOULSET_H
