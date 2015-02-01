#ifndef SERGUI_H_INCLUDED
#define SERGUI_H_INCLUDED

#include <SFML/Graphics.hpp>

namespace SerGUI
{
    extern const std::string TXT_TITLE_SCREEN;
    extern const std::string TXT_MENU_TITLE_SAVE;
    extern const std::string TXT_MENU_TITLE_PLAY;
    extern const std::string TXT_MENU_TITLE_ERASE;
    extern const std::string TXT_MENU_TITLE_COPY;

    extern sf::Texture texMenuTitleBG;
    extern sf::Texture texMenuSelectSaveButtonNbSave;
    extern sf::Texture texMenuSelectSaveButtonNbSaveSelected;
    extern sf::Texture texMenuSelectSaveButtonAction;
    extern sf::Texture texMenuSelectSaveButtonActionSelected;

    extern sf::Font fontMenu1;

    extern sf::RenderWindow window;

    bool Load();
    void Free();
}


#endif // SERGUI_H_INCLUDED
