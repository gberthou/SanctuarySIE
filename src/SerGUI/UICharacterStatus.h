#ifndef UICHARACTERSTATUS_H
#define UICHARACTERSTATUS_H

#include <SFML/Graphics.hpp>
#include "Character.h"

class UICharacterStatus : public sf::Drawable, protected sf::Transformable
{
    public:
        UICharacterStatus(Character *character);
        virtual ~UICharacterStatus();

        bool Load();
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        void Update();
        void SetPosition(sf::Vector2f pos);
    protected:
        
        Character* character;
        
        sf::Texture textureUICharacterStatus;
        sf::Sprite spriteUI;
        sf::Sprite spriteHp;
        sf::Sprite spriteMp;
        sf::Text textHp;
};


#endif // UICHARACTERSTATUS_H_INCLUDED
