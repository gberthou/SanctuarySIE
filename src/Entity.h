#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/System.hpp>
#include "Physics.h"

class Entity
{
    public:
        void Update();

    private:
        float mass;
        sf::Vector2f pos;
        sf::Vector2f v;
        sf::Vector2f a;
        sf::Vector2f forces;
        sf::Vector2f fun;
};

#endif
