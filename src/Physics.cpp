#include "Entity.h"
#include "Physics.h"
#include <iostream>
using namespace std;

const float DT = 0.015625f; // 1/64 s
const sf::Vector2f GRAVITY(0,9.81f*100.f);

Physics::Physics(CollisionMap cm):
	collisionMap(cm)
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

void Physics::manageStaticCollisions(Entity* e)
{
    //// Forces
    
    //// Map bounds collisions
    
    
    // Entity too on the left
    if(e->hitbox.pos.x < 0)
    {
        e->hitbox.pos.x = 0;
        e->forces.x = e->forces.x < 0 ? 0 : e->forces.x;
        e->a.x = e->a.x < 0 ? 0 : e->a.x;
        e->v.x = e->v.x < 0 ? 0 : e->v.x;
    }
    // Entity too on the right
    else if(e->hitbox.pos.x+e->hitbox.size.x > collisionMap->getSize().x)
    {
        e->hitbox.pos.x = collisionMap->getSize().x - e->hitbox.size.x;
        e->forces.x = e->forces.x > 0 ? 0 : e->forces.x;
        e->a.x = e->a.x > 0 ? 0 : e->a.x;
        e->v.x = e->v.x > 0 ? 0 : e->v.x;
    }
    
    //// Structure collisions
    
    
    if (e->hitbox.pos.y > 0
        && e->hitbox.pos.y+e->hitbox.size.y < collisionMap->getSize().y
        && isThereStaticCollision(e))
    {
        int xCorrection = computeHorizontalStaticCorrection(e);
        e->hitbox.pos.x+=xCorrection;
        int yCorrection = computeVerticalStaticCorrection(e);
        if (yCorrection > 0)
        {
            e->forces.y = e->forces.y < 0 ? 0 : e->forces.y;
            e->a.y = e->a.y < 0 ? 0 : e->a.y;
            e->v.y = e->v.y < 0 ? 0 : e->v.y;
        }
        else if (yCorrection < 0)
        {
            e->forces.y = 0;
            e->a.y = 0;
            e->v.y = 0;
            e->onGround = true;
        }
        e->hitbox.pos.y+=yCorrection;
    }
    else
    {
        e->onGround = false;
        e->forces = GRAVITY;
    }
	
	e->pos = e->hitbox.pos - e->hitboxOffset;
}

bool Physics::isThereStaticCollision(Entity* e)
{
    for(unsigned int x=e->hitbox.pos.x;
        x<e->hitbox.pos.x+e->hitbox.size.x;
        ++x)
    {
        for(unsigned int y=e->hitbox.pos.y;
                y<e->hitbox.pos.y+e->hitbox.size.y;
                ++y)
        {
            if(collisionMap->getPixel(x,y).a > 0)
            {
                return true;
            }
        }
    }
    return false;
}

int Physics::computeVerticalStaticCorrection(Entity* e)
{
    unsigned int x = (2*e->hitbox.pos.x+e->hitbox.size.x-1)/2;
    unsigned int yBottom = e->hitbox.pos.y+e->hitbox.size.y-1;
    
    // Test the map collision vertical bounds
    if (e->hitbox.pos.y < 0)
    {
        return -e->hitbox.pos.y;
    }
    else if (yBottom+1 > collisionMap->getSize().y)
    {
        return collisionMap->getSize().y-1 - yBottom;
    }
    
    // Search the highest collision point
    int y; // y coordinate of the collision point
    for(y=0;
        y < e->hitbox.size.y
            && collisionMap->getPixel(x,yBottom+y).a > 0;
        --y);
    return y;
}

int Physics::computeHorizontalStaticCorrection(Entity* e)
{
    unsigned int yMiddle = e->hitbox.pos.y+(e->hitbox.size.y-1)/2;
    unsigned int xRight = e->hitbox.pos.x+e->hitbox.size.x-1;
    
    // Test the map collision bounds
    if (e->hitbox.pos.x < 0)
    {
        return -e->hitbox.pos.x;
    }
    else if (xRight+1 > collisionMap->getSize().x)
    {
        return collisionMap->getSize().x-1 - xRight;
    }
    
    int halfWidth = e->hitbox.size.x/2;
    int x;
    for(x = halfWidth;
        x >= 0
            && collisionMap->getPixel(e->hitbox.pos.x+x,yMiddle).a == 0;
        --x);
    if(x >= 0)
    {
        return halfWidth-x;
    }
    for(x = halfWidth;
        x < e->hitbox.size.x
            && collisionMap->getPixel(e->hitbox.pos.x+x,yMiddle).a == 0;
        ++x);
    if(x >= e->hitbox.size.x)
        return 0;
    return halfWidth-x;
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
