#include "UICharacterStatus.h"
#include "SerGUI.h"
#include "Utils.h"

static const char* S_IMAGE_UI("img/sergui/UICharacterStatus.png");
static sf::IntRect DEFAULT_TEXTURE_RECT [] = {
    sf::IntRect(0,0,238,33), // ui
    sf::IntRect(239,0,1,10), // hp bar
    sf::IntRect(239,10,1,10) // mana bar
    };
static sf::IntRect DEFAULT_SPRITE_POSITION [] = {
    sf::IntRect(8,4,30,20),  // text
    sf::IntRect(49,5,186,9), // hp pos
    sf::IntRect(49,19,186,9) // mana pos
    };
static const unsigned int UI_TEXT_SIZE = 18;

UICharacterStatus::UICharacterStatus()
{
    load();
    spriteUI.setTexture(textureUICharacterStatus);
    spriteHp.setTexture(textureUICharacterStatus);
    spriteMp.setTexture(textureUICharacterStatus);
    
    spriteUI.setTextureRect(DEFAULT_TEXTURE_RECT[0]);
    spriteHp.setTextureRect(DEFAULT_TEXTURE_RECT[1]);
    spriteMp.setTextureRect(DEFAULT_TEXTURE_RECT[2]);
    
    spriteHp.setPosition(DEFAULT_SPRITE_POSITION[1].left,DEFAULT_SPRITE_POSITION[1].top);
    spriteMp.setPosition(DEFAULT_SPRITE_POSITION[2].left,DEFAULT_SPRITE_POSITION[2].top);
    textHp.setFont(SerGUI::fontMenu1);
    textHp.setPosition(DEFAULT_SPRITE_POSITION[0].left,DEFAULT_SPRITE_POSITION[0].top);
    textHp.setCharacterSize(UI_TEXT_SIZE);
}

UICharacterStatus::~UICharacterStatus()
{
}

bool UICharacterStatus::load()
{
    return textureUICharacterStatus.loadFromFile(S_IMAGE_UI);
}

void UICharacterStatus::SetCharacter(Character* ncharacter)
{
    character = ncharacter;
    Update();
}

void UICharacterStatus::Update()
{
    textHp.setString(ttos(character->GetHP()));
    // center the text :
    textHp.setPosition(DEFAULT_SPRITE_POSITION[0].left+(DEFAULT_SPRITE_POSITION[0].width-textHp.getGlobalBounds().width)/2.0f,
                       DEFAULT_SPRITE_POSITION[0].top);
    spriteHp.setScale((float)character->GetHP()/character->GetMaxHP()*DEFAULT_SPRITE_POSITION[1].width,1.0f);
    spriteMp.setScale((float)character->GetMP()/character->GetMaxMP()*DEFAULT_SPRITE_POSITION[2].width,1.0f);
}

void UICharacterStatus::SetPosition(sf::Vector2f pos)
{
    setPosition(pos);
}

void UICharacterStatus::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(spriteUI,states);
    target.draw(spriteMp,states);
    target.draw(spriteHp,states);
    target.draw(textHp,states);
}
