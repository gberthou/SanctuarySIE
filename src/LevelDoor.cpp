#include "LevelDoor.h"

//#define DEBUG_SYMMETRY

static inline float dotProduct(const sf::Vector2f &u, const sf::Vector2f &v)
{
	return u.x * v.x + u.y * v.y;
}

static inline float fabs(float x)
{
	return x < 0 ? -x : x;
}

LevelDoor::LevelDoor(IdLevel idLevel1, const AABB &hitbox1, unsigned int lx1, unsigned int ly1, DoorDirection dir):
	idLevel(idLevel1),
	target(0),
	hitbox(hitbox1),
	lx(lx1),
	ly(ly1),
	direction(dir)
{
}

LevelDoor::~LevelDoor()
{
}

void LevelDoor::SetTarget(const LevelDoor *target1)
{
	target = target1;
}

bool LevelDoor::CollidesWith(const Entity *entity) const
{
	return hitbox.CollidesWith(entity->GetHitbox());
}

IdLevel LevelDoor::GetIdLevel(void) const
{
	return idLevel;
}

const LevelDoor *LevelDoor::GetTarget(void) const
{
	return target;
}

const AABB &LevelDoor::GetHitbox(void) const
{
	return hitbox;
}

unsigned int LevelDoor::GetLocalX(void) const
{
	return lx;
}

unsigned int LevelDoor::GetLocalY(void) const
{
	return ly;
}

DoorDirection LevelDoor::GetDirection(void) const
{
	return direction;
}

sf::Vector2f LevelDoor::GetSymmetricalPoint(const Entity *entity) const
{
	// U[i]: unit normal "through" the door
	const sf::Vector2f U[4] = {sf::Vector2f(-1, 0), sf::Vector2f(0, -1), sf::Vector2f(0, 1), sf::Vector2f(1, 0)};
	
	// V[i]: arbitrary unit vector orthogonal to the normal vector (the corresponding U[i])
	const sf::Vector2f V[4] = {sf::Vector2f(0, 1), sf::Vector2f(1, 0), sf::Vector2f(1, 0), sf::Vector2f(0, 1)};
	
	const float SAFE_OFFSET = 2.f; // Unit: pixels

	sf::Vector2f O = hitbox.GetCenter();
	sf::Vector2f PO = O - entity->GetCenter();
	sf::Vector2f H = O - V[direction] * dotProduct(PO, V[direction]);
	sf::Vector2f ret = H + U[direction] * (fabs(dotProduct(hitbox.GetSize() + entity->GetHitbox().GetSize(), U[direction]) / 2.f) + SAFE_OFFSET);

#ifdef DEBUG_SYMMETRY
	std::cout << "in:  (" << entity->GetCenter().x << ", " << entity->GetCenter().y << ")" << std::endl;
	std::cout << "O:   (" << O.x << ", " << O.y << ")" << std::endl;
	std::cout << "H:   (" << H.x << ", " << H.y << ")" << std::endl;
	std::cout << "out: (" << ret.x << ", " << ret.y << ")" << std::endl;
	std::cout << std::endl;
#endif

	return ret;
}

