#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class Button : public sf::Drawable
{
    public:
        Button();
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        void SetTextureDefault(sf::Texture* texture);
        void SetTextureSelected(sf::Texture* texture);
        void SetText(std::string const& text);
        void SetFont(sf::Font const& font, unsigned int fontSize);
        void Select();
        void Unselect();
        void Lock();
        void Unlock();
        void SetPosition(float x, float y);

    protected:
        sf::Texture* textureDefault;
        sf::Texture* textureSelected;
        sf::Sprite background;
        sf::Text text;
};


#endif // BUTTON_H
