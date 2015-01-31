#include "Entity.h"
#include "Physics.h"
#include <iostream>
using namespace std;

const float DT = 0.015625f; // 1/64 s
const sf::Vector2f GRAVITY(0,9.81f*0.1f);

Physics::Physics()
{

}

Physics::~Physics()
{

}

void Physics::AddEntity(Entity* entity)
{
    entities.push_back(entity);
}

void Physics::CleanEntities()
{
    entities.clear();
}

void Physics::AddCollisionMap(sf::Image* bitmap)
{
    collisionMap = bitmap;
}

void Physics::manageStaticCollisions(Entity* e)
{
    if( !(e->pos.x < 0 || e->pos.x+e->GetSprite().getGlobalBounds().width > collisionMap->getSize().x
       || e->pos.y < 0 || e->pos.y+e->GetSprite().getGlobalBounds().height > collisionMap->getSize().y) )
    {

        for(unsigned int x=e->pos.x;
            x<e->pos.x+e->GetSprite().getGlobalBounds().width;
            ++x)
        {
            for(unsigned int y=e->pos.y;
                    y<e->pos.y+e->GetSprite().getGlobalBounds().height;
                    ++y)
            {
                if(collisionMap->getPixel(x,y).r > 0)
                {
                    e->forces = sf::Vector2f();
                    e->a = sf::Vector2f();
                    e->v = sf::Vector2f();
                    return;
                }
            }
        }
        cout<<endl;
    }
    e->forces = GRAVITY;
}

void Physics::Update()
{

    // bitmap collision
    for(unsigned int i=0; i<entities.size(); ++i)
    {
        manageStaticCollisions(entities[i]);
    }

    for(unsigned int i=0; i<entities.size(); ++i)
    {
        entities[i]->Update();
    }
}
