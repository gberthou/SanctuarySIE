#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED

#include "Level.h"
#include "Character.h"

class Save
{
    public:
        Save(int idsave, Level** nlevel, Character** ncharacter);
        bool LoadFromFile();
        bool SaveToFile();
        
    protected:
        static void beginGame(Level** level, Character** c);
        int idSave;
        
        Level **level;
        Character **character;
        
};


#endif // SAVE_H_INCLUDED
