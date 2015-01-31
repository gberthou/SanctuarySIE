#ifndef PERMANENT_H
#define PERMANENT_H

#include "Tradable.h"


class Permanent : public Tradable
{
    public:
        Permanent(sf::String name1, sf::String description1, bool trade1, unsigned int sellPrice1, unsigned int buyPrice1);
        virtual ~Permanent();
    protected:
    private:
};

#endif // PERMANENT_H
