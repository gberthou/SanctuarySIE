#ifndef PHYSICS_H
#define PHYSICS_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

extern const float DT;
extern const sf::Vector2f GRAVITY;

typedef sf::Image *CollisionMap;

class Physics
{
    public:
        Physics(CollisionMap collisionMap);
        virtual ~Physics();
        void Update();
        void AddEntity(Entity* entity);
        void RemoveEntity(const Entity *entity);
		//void CleanEntities();

    protected:
        void manageStaticCollisions(Entity* e);
        bool isThereStaticCollision(Entity* e);
        int computeHorizontalStaticCorrection(Entity* e);
        int computeVerticalStaticCorrection(Entity* e);

    private:
        std::vector<Entity*> entities;
        CollisionMap collisionMap;
};

#endif // PHYSICS_H

