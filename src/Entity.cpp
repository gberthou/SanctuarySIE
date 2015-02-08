#include "Entity.h"

Entity::Entity():
    mass(1), onGround(false)
{
}

Entity::~Entity()
{
}

void Entity::Update()
{
    a += forces/mass;
    v += a*DT;
    pos += v*DT;

	a = sf::Vector2f();

    sprite.setPosition(pos);
}

void Entity::SetPosition(const sf::Vector2f &position)
{
	pos = position;
	sprite.setPosition(pos);
}

void Entity::AddForce(const sf::Vector2f &force)
{
	forces += force;
}

void Entity::AddImpulse(const sf::Vector2f &impulse)
{
	v += impulse/mass;
}

void Entity::AddAcceleration(const sf::Vector2f &acceleration)
{
	a += acceleration;
}

void Entity::AddVelocity(const sf::Vector2f &velocity)
{
	v += velocity;
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

sf::Sprite const& Entity::GetSprite() const
{
    return sprite;
}

sf::Vector2f Entity::GetPos() const
{
    return pos;
}

void Entity::SetJumping()
{
    onGround = false;
}


