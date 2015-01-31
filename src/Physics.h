#ifndef PHYSICS_H
#define PHYSICS_H

#include <SFML/System.hpp>
#include <vector>

extern const float DT;
extern const sf::Vector2f GRAVITY;

class Entity;
class Physics
{
    public:
        Physics();
        virtual ~Physics();
        void Update();
        void AddEntity(Entity* entity);
        void CleanEntities();
        void AddCollisionMap(sf::Image* bitmap);

    protected:
        void manageStaticCollisions(Entity* e);

    private:
        std::vector<Entity*> entities;
        sf::Image* collisionMap;
};

#endif // PHYSICS_H
