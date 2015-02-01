#ifndef PHYSICS_H
#define PHYSICS_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

extern const float DT;
extern const sf::Vector2f GRAVITY;

class Entity;

typedef sf::Image *CollisionMap;

class Physics
{
    public:
        Physics(CollisionMap collisionMap);
        virtual ~Physics();
        void Update();
        void AddEntity(Entity* entity);
        void CleanEntities();
		
		// Is the following method useful as you already specify the collision
		// map to the constructor, and there's no reason to change it while
		// playing in the same level? (Actually there's a Physics instance in
		// each level)
        void SetCollisionMap(CollisionMap bitmap);
        
		// Please delete the following method, and replace it with SetCollisionMap
		void AddCollisionMap(CollisionMap bitmap);

    protected:
        void manageStaticCollisions(Entity* e);

    private:
        std::vector<Entity*> entities;
        CollisionMap collisionMap;
};

#endif // PHYSICS_H

