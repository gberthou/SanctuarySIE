#include <cstdlib>

#include "Bat.h"

const unsigned int FRAME_WIDTH = 200;
const unsigned int FRAME_HEIGHT = 100;
const unsigned int FRAME_NUMBER = 3;

Bat::Bat(const sf::Texture &texture):
	sf::Drawable(),
	sprite(texture),
	animation(0, FRAME_NUMBER-1, 2)
{

}

Bat::~Bat()
{
}

void Bat::Update(void)
{
	if(!animation.IsPlaying())
		animation.Start(rand() % (FRAME_NUMBER - 1));

	sprite.setTextureRect(sf::IntRect(FRAME_WIDTH * animation.GetFrame(), 0, FRAME_WIDTH, FRAME_HEIGHT));
	sprite.setPosition(pos);

	animation.Update();
}

void Bat::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}

