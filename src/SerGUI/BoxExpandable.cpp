#include "BoxExpandable.h"
#include "SerGUI.h"

static const int NB_PART(9);
static const char* S_BUTTON_ACTION("img/sergui/maimenu_element2.png");

// useful for testing:
static sf::Texture* DEFAULT_TEXTURE(0);
static sf::IntRect DEFAULT_TEXTURE_RECT [] = {
        sf::IntRect(0,0,88,38), // corner top left
        sf::IntRect(88,0,1,38), // top
        sf::IntRect(268,0,88,38), // corner top right
        
        sf::IntRect(0,38,88,1), // left
        sf::IntRect(88,38,1,1), // middle
        sf::IntRect(268,38,88,1), // right
        
        sf::IntRect(0,50,88,38), // corner
        sf::IntRect(88,50,1,38), // bottom
        sf::IntRect(268,50,88,38) // corner bottom right
};

void AutoCutText(sf::Text & text, std::string const& str, unsigned int widthMax)
{
    std::string nstr;
    nstr.resize(str.size()+8,' ');
    unsigned int width = 0;
    unsigned int widthWord = 0;
    unsigned int nbLine = 0;
    for(unsigned int i=0,j=0,k=0;i<str.size();)
    {
        if(widthWord == 0)
        {
            for(k=0;str[i+k] != ' ' && i+k<str.size();++k)
            {
                 widthWord += text.getFont()->getGlyph(sf::String(str[i+k])[0],text.getCharacterSize(),false).bounds.width;
            }
        }
        if(width+widthWord < widthMax || widthWord >= widthMax)
        {
            for(unsigned int c=0;c<k;++c)
            {
                nstr[j++] = str[i++];
            }
            i++;
            nstr[j++] = ' ';
            width += widthWord+0*text.getFont()->getGlyph(sf::String('l')[0],text.getCharacterSize(),false).bounds.width;
            widthWord = 0;
        }
        else
        {
            ++nbLine;
            if(nbLine>=8)
               nstr.append("        "); 
            nstr[j++] = '\n';
            width = 0;
        }
    }
    text.setString(nstr);
}

BoxExpandable::BoxExpandable() :
    texture(0)
{
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(NB_PART * 4);
}

BoxExpandable::~BoxExpandable()
{
    delete DEFAULT_TEXTURE;
}

void BoxExpandable::SetTexture(sf::Texture* tex, sf::IntRect n_texRect[9])
{
    if((texture = tex))
        texture->setRepeated(true);
    for(int i=0;i<9;++i)
    {
        texRect[i] = n_texRect[i];
    }
}

void BoxExpandable::SetTextAuto(std::string const& str)
{
    AutoCutText(text,str,GetCenterSize().x-textOffset.x*2);
    // work only if its symmetric 
}

void BoxExpandable::SetDefaultTexture()
{
    if(!DEFAULT_TEXTURE)
    {
        DEFAULT_TEXTURE = new sf::Texture();
        DEFAULT_TEXTURE->loadFromFile(S_BUTTON_ACTION);
    }
    SetTexture(DEFAULT_TEXTURE,DEFAULT_TEXTURE_RECT);
    text.setFont(SerGUI::fontMenu1);
    text.setCharacterSize(24);
    
}

void BoxExpandable::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = texture;
    target.draw(m_vertices,states);
    target.draw(text,states);
}

void BoxExpandable::SetSize(sf::Vector2i n_size)
{
    boxSize = n_size;
    computeSprite();
}

void BoxExpandable::SetPosition(sf::Vector2f pos)
{
    sf::Transformable::setPosition(pos);
}

void BoxExpandable::SetRect(sf::IntRect rect)
{
    SetPosition(sf::Vector2f(rect.left,rect.top));
    SetSize(sf::Vector2i(rect.width,rect.height));
}

void BoxExpandable::SetRect(sf::FloatRect rect)
{
    SetRect(rect);
}

void BoxExpandable::SetTextPositionOffset(sf::Vector2f const& offset)
{
    textOffset = offset;
    text.setPosition(sf::Vector2f(texRect[0].width,texRect[0].height)+textOffset);
}

sf::Vector2f BoxExpandable::GetCenterSize() const
{
    return ((sf::Vertex*)&m_vertices[1*4])[2].position;
}

// PROTECTED ---

void BoxExpandable::computeSprite()
{
    sf::Vertex* quad;
    for(int i=0;i<NB_PART;++i)
    {
        quad = &m_vertices[i*4];
        quad[0].position = sf::Vector2f(0, 0);
        quad[1].position = sf::Vector2f(texRect[i].width,0);
        quad[2].position = sf::Vector2f(texRect[i].width,texRect[i].height);
        quad[3].position = sf::Vector2f(0,texRect[i].height);
        quad[0].texCoords = sf::Vector2f(texRect[i].left, texRect[i].top);
        quad[1].texCoords = sf::Vector2f(texRect[i].left+texRect[i].width, texRect[i].top);
        quad[2].texCoords = sf::Vector2f(texRect[i].left+texRect[i].width, texRect[i].top+texRect[i].height);
        quad[3].texCoords = sf::Vector2f(texRect[i].left, texRect[i].top+texRect[i].height);
    }
    sf::Vector2i realSize = boxSize;
    for(int i=0;i<3;++i)
    {
        realSize.x -= texRect[i].width;
        realSize.y -= texRect[i*3].height;
    }
    for(int y=0;y<3;++y)
    {
        for(int x=0;x<3;++x)
        {
            int id = x+y*3;
            quad = &m_vertices[id*4];
            if(x == 1)
            {
                quad[1].position.x += realSize.x;
                quad[2].position.x += realSize.x;
            }
            if(y == 1)
            {
                quad[2].position.y += realSize.y;
                quad[3].position.y += realSize.y;
            }
            if(x == 2)
            {
                for(int k=0;k<4;++k)
                    quad[k].position.x += realSize.x;
            }
            if(y == 2)
            {
                for(int k=0;k<4;++k)
                    quad[k].position.y += realSize.y;
            }
            for(int i=1;i<=x;++i)
            {
                for(int k=0;k<4;++k)
                    quad[k].position.x += texRect[id-i].width;
            }
            for(int i=1;i<=y;++i)
            {
                for(int k=0;k<4;++k)
                    quad[k].position.y += texRect[id-i*3].height;
            }
        }
    }
    text.setPosition(sf::Vector2f(texRect[0].width,texRect[0].height)+textOffset);
}
