#include "Button.h"

Button::Button()
{
}

void Button::SetPosition(float x, float y)
{
    background.setPosition(x,y);
    text.setPosition(x,y);
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(background);
    target.draw(text);
}

void Button::SetTextureDefault(sf::Texture* texture)
{
    textureDefault = texture;
    background.setTexture(*textureDefault);
    background.setOrigin(textureDefault->getSize().x/2.f,
                         textureDefault->getSize().y/2.f);
}

void Button::SetTextureSelected(sf::Texture* texture)
{
    textureSelected = texture;
}

void Button::SetText(std::string const& t)
{
    text.setString(t);
    text.setOrigin(text.getGlobalBounds().width/2.f,
                   text.getGlobalBounds().height*1.f);
}

void Button::SetFont(sf::Font const& font, unsigned int fontSize)
{
    text.setFont(font);
    text.setCharacterSize(fontSize);
}

void Button::Select()
{
    background.setTexture(*textureSelected);
}

void Button::Unselect()
{
    background.setTexture(*textureDefault);
}

void Button::Lock()
{
    text.setColor(sf::Color(255,255,255,128));
}

void Button::Unlock()
{
    text.setColor(sf::Color(255,255,255,255));
}
