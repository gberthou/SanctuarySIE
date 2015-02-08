#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Physics.h"

class Entity : public sf::Drawable
{
    public:
        Entity();
        virtual ~Entity();
        virtual void Update();

        void SetPosition(const sf::Vector2f &pos);
        void AddForce(const sf::Vector2f &force);
        void AddImpulse(const sf::Vector2f &impulse);
        void AddAcceleration(const sf::Vector2f &acceleration);
        void AddVelocity(const sf::Vector2f &velocity);

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        sf::Sprite const& GetSprite() const;
        sf::Vector2f GetPos() const;
        void SetJumping();

    protected:
        float mass;
        sf::Vector2f pos;
        sf::Vector2f v;
        sf::Vector2f a;
        sf::Vector2f forces;
        bool onGround;

        sf::Sprite sprite;

    private:

        friend class Physics;
};

#endif
