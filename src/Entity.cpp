#include "Entity.h"

Entity::Entity():
    mass(1)
{
}

Entity::~Entity()
{
}

void Entity::Update()
{
    a = forces/mass;
    v += a*DT;
    pos += v*DT;

    sprite.setPosition(pos);
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

sf::Sprite const& Entity::GetSprite() const
{
    return sprite;
}
