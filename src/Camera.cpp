#include "Camera.h"

Camera::Camera() :
    sf::View()
{
    
}

Camera::Camera(const sf::FloatRect &rectangle) :
    sf::View(rectangle)
{
    
}

Camera::Camera(const sf::Vector2f &center, const sf::Vector2f &size) :
    sf::View(center, size)
{
    
}

Camera::~Camera()
{
    
}

void Camera::Update(Level* level, Character* character)
{
    
    unsigned int dx = getSize().x/2;
    unsigned int dy = getSize().y/2;
    unsigned int xView = 0;
    unsigned int yView = 0;
    unsigned int viewLeftLimit;
    unsigned int viewRightLimit;
    unsigned int viewTopLimit;
    unsigned int viewBottomLimit;
    
    if (character == 0 || level == 0)
    {
        return;
    }
    
    // By default, the camera is centered on the character
    xView = character->GetPos().x;
    yView = character->GetPos().y;
    
    // Computing the the borders camera bounds
    viewLeftLimit = level->GetX() + dx;
    viewRightLimit = level->GetX() + level->GetWidth() - 1 - dx;
    viewTopLimit = level->GetY() + dy;
    viewBottomLimit = level->GetY() + level->GetHeight() - 1 - dy;
    
    // Center the camera correctly (x-axis)
    if      (viewLeftLimit > viewRightLimit)
        xView = (viewLeftLimit + viewRightLimit) / 2;
    else if (xView < viewLeftLimit)
        xView = viewLeftLimit;
    else if (xView > viewRightLimit)
        xView = viewRightLimit;
        
    // Center the camera correctly (y-axis)
    if      (viewTopLimit > viewBottomLimit)
        yView = (viewTopLimit + viewBottomLimit) / 2;
    else if (yView < viewTopLimit)
        yView = viewTopLimit;
    else if (yView > viewBottomLimit)
        yView = viewBottomLimit;
    
    // Change the camera center
    setCenter(sf::Vector2f(xView,yView));
    
    // Change the level POV (parallax)
    level->SetPOV(sf::Vector2f(xView*0.20,0));
}
