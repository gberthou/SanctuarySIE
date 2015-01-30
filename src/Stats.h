#ifndef STATS_H
#define STATS_H

#include <SFML/System.hpp>

class Stats
{
    public:
        Stats(int att1, int def1, int str1, int con1, int intel1, int luck1);
        virtual ~Stats();
    protected:
    private:
        // Real stats
        int att;
        int def;
        int str;
        int con;
        int intel;
        int luck;

        // Labels
        static const sf::String ATT;
        static const sf::String DEF;
        static const sf::String STR;
        static const sf::String CON;
        static const sf::String INTEL;
        static const sf::String LUCK;

};

#endif // STATS_H
