#include "Entity.h"
#include "Physics.h"

Entity::Entity():
    mass(1),
	onGround(false),
	mapCollisionEnabled(true)
{
}

Entity::~Entity()
{
}

void Entity::Update()
{
    a += forces/mass;
    v += a*DT;
    
	AddPosition(v*DT);

	a = sf::Vector2f();
}

void Entity::SetPosition(const sf::Vector2f &position)
{
	pos = position;
	
	hitbox.SetPosition(pos + hitboxOffset);
	sprite.setPosition(pos);
}

void Entity::AddPosition(const sf::Vector2f &delta)
{
	SetPosition(pos + delta);
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

void Entity::SetVelocity(const sf::Vector2f &velocity)
{
	v = velocity;
}

void Entity::SetVelocityY(float vy)
{
	v.y = vy;
}

void Entity::SetHitbox(const AABB &hitbox1, const sf::Vector2f &offset)
{
	hitbox = hitbox1;
	hitboxOffset = offset;
}

bool Entity::CollidesWith(const Entity *entity) const
{
	return hitbox.CollidesWith(entity->hitbox);
}

bool Entity::CollidesWith(const sf::Vector2f &point) const
{
	return hitbox.CollidesWith(point);
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

sf::Vector2f Entity::GetCenter() const
{
	return pos + hitboxOffset + hitbox.GetSize() / 2.f;
}

sf::Vector2f Entity::GetVelocity() const
{
	return v;
}

void Entity::SetJumping()
{
    onGround = false;
}

void Entity::SetMapCollisionEnabled(bool enabled)
{
	mapCollisionEnabled = enabled;
}

bool Entity::IsMapCollisionEnabled() const
{
	return mapCollisionEnabled;
}

