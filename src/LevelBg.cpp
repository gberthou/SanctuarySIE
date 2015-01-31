#include "LevelBg.h"

const float LAYER_VELOCITY[BG_LAYERS] = {1.f, .75f, .25f, 0.f};

LevelBg::LevelBg():
	sf::Drawable()
{
	for(unsigned int i = 0; i < BG_LAYERS; ++i)
		img[i] = 0;
}

LevelBg::~LevelBg()
{
	for(unsigned int i = 0; i < BG_LAYERS; ++i)
		if(img[i] != 0)
			delete img[i];
}

void LevelBg::SetLayer(unsigned int layerId, const sf::String &filename)
{
	if(layerId < BG_LAYERS)
	{
		if(img[layerId] != 0)
			delete img[layerId];

		img[layerId] = new sf::Image();
		img[layerId]->loadFromFile(filename);
		bg[layerId].loadFromImage(*img[layerId]);
	}
}

void LevelBg::SetOffset(sf::Vector2f offset1)
{
	offset = offset1;
}
		
void LevelBg::draw (sf::RenderTarget &target, sf::RenderStates states) const
{
	for(int i = BG_LAYERS - 1; i >= 0; --i)
	{
		if(img[i] != 0)
		{
			sf::Sprite sprite(bg[i]);
			sprite.setPosition(-offset * LAYER_VELOCITY[i]);
			target.draw(sprite, states);
		}
	}
}

