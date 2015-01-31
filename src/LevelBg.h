#ifndef LEVELBG_H
#define LEVELBG_H

#include <SFML/Graphics.hpp>

#define BG_LAYERS 4

class LevelBg : public sf::Drawable
{
	public:
		LevelBg();
		virtual ~LevelBg();

		void SetLayer(unsigned int layerId, const sf::String &filename);
		void SetOffset(sf::Vector2f offset);

		void draw (sf::RenderTarget &target, sf::RenderStates states) const;

	private:
		sf::Image *img[BG_LAYERS];
		sf::Texture bg[BG_LAYERS];

		sf::Vector2f offset;
};

#endif

