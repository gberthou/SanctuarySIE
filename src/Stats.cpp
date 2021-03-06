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

Stats::Stats()
{
    att = 0;
    def = 0;
    str = 0;
    con = 0;
    intel = 0;
    luck = 0;
}

Stats::Stats(const Stats &other):
	att(other.att),
	def(other.def),
	str(other.str),
	con(other.con),
	intel(other.intel),
	luck(other.luck)
{
}

Stats::~Stats()
{
}

int Stats::GetAtt() const
{
    return att;
}

int Stats::GetDef() const
{
    return def;
}

int Stats::GetStr() const
{
    return str;
}

int Stats::GetCon() const
{
    return con;
}

int Stats::GetInt() const
{
    return intel;
}

int Stats::GetLck() const
{
    return luck;
}

void Stats::ModifyStats(Stats *stats1)
{
    att = (att + stats1->GetAtt() > 0) ? (att + stats1->GetAtt() < MAX_STAT ? att + stats1->GetAtt() : MAX_STAT) : 0;
    def = (def + stats1->GetDef() > 0) ? (def + stats1->GetDef() < MAX_STAT ? def + stats1->GetDef() : MAX_STAT) : 0;
    str = (str + stats1->GetStr() > 0) ? (str + stats1->GetStr() < MAX_STAT ? str + stats1->GetStr() : MAX_STAT) : 0;
    con = (con + stats1->GetCon() > 0) ? (con + stats1->GetCon() < MAX_STAT ? con + stats1->GetCon() : MAX_STAT) : 0;
    intel = (intel + stats1->GetInt() > 0) ? (intel + stats1->GetInt() < MAX_STAT ? intel + stats1->GetInt() : MAX_STAT) : 0;
    luck = (luck + stats1->GetLck() > 0) ? (luck + stats1->GetLck() < MAX_STAT ? luck + stats1->GetLck() : MAX_STAT) : 0;
}
