#ifndef GUIBAT_H
#define GUIBAT_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Animation.h"

class Bat : public sf::Drawable
{
	public:
		Bat(const sf::Texture &texture);
		virtual ~Bat();

		void Update(void);

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	private:
		sf::Sprite sprite;
		sf::Vector2f pos;
		sf::Vector2f objective;
		Animation animation;
		float scale;
};

#endif

