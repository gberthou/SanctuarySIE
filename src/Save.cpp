#include "Save.h"

#include <iostream>
#include <fstream>
#include "Utils.h"

using namespace std;

static const char* S_FILENAME="savefile";

Save::Save(int id, Map** nmap, Character** ncharacter):
    idSave(id), map(nmap), character(ncharacter)
{
    
}

bool Save::LoadFromFile()
{
    ifstream file;
    file.open((S_FILENAME+ttos(idSave)).c_str(), ios::in | ios::binary);

    if(!file)
    {
        // if the save isn't found
        beginGame(map, character);
        return false;
    }
  
    // read the current level
    unionLevel idLevel;
    file.read((char*)&idLevel.id,sizeof(idLevel.id));
    
    beginGame(map, character, idLevel.level);
    
    // read the character infos
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
       
    // write the level id
    unionLevel idLevel = {(**map).GetCurrentLevelId()};
    file.write((char*)&idLevel,sizeof(idLevel));
    // then the character infos
    file<<**character;
    
    file.close();
    return true;
}

// (static function)
void Save::beginGame(Map** map, Character** c, IdLevel level)
{
    (*map)->SetCurrentLevel(level);
	*c = new Character(new Stats(10,6,10,12,11,9),320,(unsigned int)a_EXP + b_EXP + c_EXP);
}
