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
    if(e->pos.x < 0)
    {
        e->pos.x = 0;
        e->forces.x = e->forces.x < 0 ? 0 : e->forces.x;
        e->a.x = e->a.x < 0 ? 0 : e->a.x;
        e->v.x = e->v.x < 0 ? 0 : e->v.x;
    }
    // Entity too on the right
    else if(e->pos.x+e->GetSprite().getGlobalBounds().width > collisionMap->getSize().x)
    {
        e->pos.x = collisionMap->getSize().x - e->GetSprite().getGlobalBounds().width;
        e->forces.x = e->forces.x > 0 ? 0 : e->forces.x;
        e->a.x = e->a.x > 0 ? 0 : e->a.x;
        e->v.x = e->v.x > 0 ? 0 : e->v.x;
    }
    
    //// Structure collisions
    
    
    if (e->pos.y > 0
        && e->pos.y+e->GetSprite().getGlobalBounds().height < collisionMap->getSize().y
        && isThereStaticCollision(e))
    {
        int xCorrection = computeHorizontalStaticCorrection(e);
        e->pos.x+=xCorrection;
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
        e->pos.y+=yCorrection;
    }
    else
    {
        e->onGround = false;
        e->forces = GRAVITY;
    }
}

bool Physics::isThereStaticCollision(Entity* e)
{
    for(unsigned int x=e->pos.x;
        x<e->pos.x+e->GetSprite().getGlobalBounds().width;
        ++x)
    {
        for(unsigned int y=e->pos.y;
                y<e->pos.y+e->GetSprite().getGlobalBounds().height;
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
    unsigned int x = (2*e->pos.x+e->GetSprite().getGlobalBounds().width-1)/2;
    unsigned int yBottom = e->pos.y+e->GetSprite().getGlobalBounds().height-1;
    
    // Test the map collision vertical bounds
    if (e->pos.y < 0)
    {
        return -e->pos.y;
    }
    else if (yBottom+1 > collisionMap->getSize().y)
    {
        return collisionMap->getSize().y-1 - yBottom;
    }
    
    // Search the highest collision point
    int y; // y coordinate of the collision point
    for(y=0;
        y < e->GetSprite().getGlobalBounds().width
            && collisionMap->getPixel(x,yBottom+y).a > 0;
        --y);
    return y;
}

int Physics::computeHorizontalStaticCorrection(Entity* e)
{
    unsigned int yMiddle = e->pos.y+(e->GetSprite().getGlobalBounds().height-1)/2;
    unsigned int xRight = e->pos.x+e->GetSprite().getGlobalBounds().width-1;
    
    // Test the map collision bounds
    if (e->pos.x < 0)
    {
        return -e->pos.x;
    }
    else if (xRight+1 > collisionMap->getSize().x)
    {
        return collisionMap->getSize().x-1 - xRight;
    }
    
    int halfWidth = e->GetSprite().getGlobalBounds().width/2;
    int x;
    for(x = halfWidth;
        x >= 0
            && collisionMap->getPixel(e->pos.x+x,yMiddle).a == 0;
        --x);
    if(x >= 0)
    {
        return halfWidth-x;
    }
    for(x = halfWidth;
        x < e->GetSprite().getGlobalBounds().width
            && collisionMap->getPixel(e->pos.x+x,yMiddle).a == 0;
        ++x);
    if(x >= e->GetSprite().getGlobalBounds().width)
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
