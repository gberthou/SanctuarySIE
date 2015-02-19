#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Level.h"

class Camera : public sf::View
{
	public:
		Camera();
        Camera(const sf::FloatRect &rectangle);
        Camera(const sf::Vector2f &center, const sf::Vector2f &size);
        virtual ~Camera();
        void Update(Level* level, const Character* character);
    protected:
	private:
};

#endif // CAMERA_H

