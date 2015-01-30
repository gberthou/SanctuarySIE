#include "Stats.h"

// Labels
const sf::String Stats::ATT = "ATT";
const sf::String Stats::DEF = "DEF";
const sf::String Stats::STR = "STR";
const sf::String Stats::CON = "CON";
const sf::String Stats::INTEL = "INT";
const sf::String Stats::LUCK = "LCK";

Stats::Stats(int att1, int def1, int str1, int con1, int intel1, int luck1)
{
    att = att1;
    def = def1;
    str = str1;
    con = con1;
    intel = intel1;
    luck = luck1;

}

Stats::~Stats()
{
}
