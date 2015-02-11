#ifndef BOXEXPANDABLE_H
#define BOXEXPANDABLE_H

#include <SFML/Graphics.hpp>
#include <string>

/** A function to make the text in str fit in the size defined by widthMax */
void AutoCropText(sf::Text& text, std::string const& str, unsigned int widthMax);

class BoxExpandable : public sf::Drawable, protected sf::Transformable
{
    public:
        BoxExpandable();
        virtual ~BoxExpandable();
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        /** Set the texture of the box
         * @param texture a pointer to the texture
         * @param n_texRect an array of IntRect containing each subtexture 
         *                  (corner + border) example :
         *                  {@code
         *                  +---+---+---+
         *                  | 0 | 1 | 2 |
         *                  +---+---+---+
         *                  | 3 | 4 | 5 |
         *                  +---+---+---+
         *                  | 6 | 7 | 8 |
         *                  +---+---+---+}
         */                                                    
        void SetTexture(sf::Texture* texture, sf::IntRect n_texRect[9]);
        void SetSize(sf::Vector2i size);
        void SetPosition(sf::Vector2f pos);
        void SetRect(sf::IntRect rect);
        void SetRect(sf::FloatRect rect);
        void SetDefaultTexture();
        void SetTextAuto(std::string const& str);
        void SetTextPositionOffset(sf::Vector2f const& offset);
        sf::Vector2f GetCenterSize() const;
        
    protected:
        /** Recompute the position of the vertices and texture coordinates*/
        void computeSprite();
        
        sf::Texture* texture;
        sf::IntRect texRect[9];
        sf::VertexArray m_vertices;
        sf::Text text;
        sf::Vector2f textOffset;
        
        sf::Vector2i boxSize;
};

#endif // BOXEXPANDABLE_H
