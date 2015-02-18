#include "Save.h"

#include <iostream>
#include <fstream>
#include "Utils.h"
#include "LevelFactory.h"

using namespace std;

static const char* S_FILENAME="savefile";

Save::Save(int id, Level** nlevel, Character** ncharacter):
    idSave(id), level(nlevel), character(ncharacter)
{
    
}

bool Save::LoadFromFile()
{
    ifstream file;
    file.open((S_FILENAME+ttos(idSave)).c_str(), ios::in | ios::binary);

    if(!file)
    {
        // if the save isn't found
        beginGame(level, character);
        return false;
    }

    beginGame(level, character);
    file>>**character;
    
    file.close();
    return true;
}

bool Save::SaveToFile()
{
    ofstream file;
    file.open((S_FILENAME+ttos(idSave)).c_str(), ios::out | ios::binary);

    if(!file)
       return false;

    file<<**character;
    
    file.close();
    return true;
}

// (static function)
void Save::beginGame(Level** lvl, Character** c)
{
	*lvl = LevelFactory::CreateLevel(CORRIDOR0);
	*c = new Character(new Stats(10,6,10,12,11,9),320,(unsigned int)a_EXP + b_EXP + c_EXP);
}
