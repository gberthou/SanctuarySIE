#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED

#include "Map.h"
#include "Character.h"

class Save
{
    public:
        Save(int idsave, Map** nmap, Character** ncharacter);
        bool LoadFromFile();
        bool SaveToFile();
        
        union unionLevel
        {
            int id;
            IdLevel level;
        };
        
    protected:
        static void beginGame(Map** nmap, Character** c, IdLevel level = CORRIDOR0);
        static void initCharacter(Character** c);
        int idSave;
        
        Map **map;
        Character **character;
        
};


#endif // SAVE_H_INCLUDED
