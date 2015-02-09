#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "AABB.h"

class Entity : public sf::Drawable
{
    public:
        Entity();
        virtual ~Entity();
        virtual void Update();

        void SetPosition(const sf::Vector2f &pos);
        void AddPosition(const sf::Vector2f &delta);
        void AddForce(const sf::Vector2f &force);
        void AddImpulse(const sf::Vector2f &impulse);
        void AddAcceleration(const sf::Vector2f &acceleration);
        void AddVelocity(const sf::Vector2f &velocity);

		void SetHitbox(const AABB &hitbox, const sf::Vector2f &offset);

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        sf::Sprite const& GetSprite() const;
        sf::Vector2f GetPos() const;
        void SetJumping();

    protected:
        float mass;
        bool onGround;

        sf::Sprite sprite;
		AABB hitbox;
		sf::Vector2f hitboxOffset;

    private:
        sf::Vector2f pos;
        sf::Vector2f v;
        sf::Vector2f a;
        sf::Vector2f forces;
        
	friend class Physics;
};

#endif
