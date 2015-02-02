#include "SerGUI.h"
#ifdef DEBUG
#include <iostream>
#endif
#include <string>

namespace SerGUI
{
    const unsigned int MIN_SCREEN_WIDTH = 800;
    const unsigned int MIN_SCREEN_HEIGHT = 600;
    unsigned int SCREEN_WIDTH = MIN_SCREEN_WIDTH;
    unsigned int SCREEN_HEIGHT = MIN_SCREEN_HEIGHT;
    unsigned int FPS = 60;

    const sf::String WINDOW_TITLE("SanctuarySIE");
    const std::string TXT_TITLE_SCREEN = "Press Enter";
    const std::string TXT_MENU_TITLE_SAVE = "Save";
    const std::string TXT_MENU_TITLE_PLAY = "Play";
    const std::string TXT_MENU_TITLE_ERASE = "Erase";
    const std::string TXT_MENU_TITLE_COPY = "Copy";

    sf::RenderWindow window;

    sf::Texture texMenuTitleBG;
    sf::Texture texMenuTitle1BG;
    sf::Texture texMenuSelectSaveButtonNbSave;
    sf::Texture texMenuSelectSaveButtonNbSaveSelected;
    sf::Texture texMenuSelectSaveButtonAction;
    sf::Texture texMenuSelectSaveButtonActionSelected;
    sf::Font fontMenu1;

    bool Load()
    {
        if(!texMenuTitleBG.loadFromFile("img/sergui/title.png"))
        {
            #ifdef DEBUG
            std::cout<<"Fail while loading resource"<<std::endl;
            #endif
            return false;
        }
        if(!texMenuTitle1BG.loadFromFile("img/sergui/title1.png"))
        {
            #ifdef DEBUG
            std::cout<<"Fail while loading resource"<<std::endl;
            #endif
            return false;
        }
        if(!texMenuSelectSaveButtonNbSave
                .loadFromFile("img/sergui/maimenu_element1.png"))
        {
            #ifdef DEBUG
            std::cout<<"Fail while loading resource"<<std::endl;
            #endif
            return false;
        }
        if(!texMenuSelectSaveButtonNbSaveSelected
                .loadFromFile("img/sergui/maimenu_element1_select.png"))
        {
            #ifdef DEBUG
            std::cout<<"Fail while loading resource"<<std::endl;
            #endif
            return false;
        }
        if(!texMenuSelectSaveButtonAction
                .loadFromFile("img/sergui/maimenu_element2.png"))
        {
            #ifdef DEBUG
            std::cout<<"Fail while loading resource"<<std::endl;
            #endif
            return false;
        }
        if(!texMenuSelectSaveButtonActionSelected
                .loadFromFile("img/sergui/maimenu_element2_select.png"))
        {
            #ifdef DEBUG
            std::cout<<"Fail while loading resource"<<std::endl;
            #endif
            return false;
        }
        if(!fontMenu1.loadFromFile("font/EnglishTowne.ttf"))
        {
            #ifdef DEBUG
            std::cout<<"Fail while loading font"<<std::endl;
            #endif
        return false;
        }
        window.create(sf::VideoMode(SerGUI::SCREEN_WIDTH,SerGUI::SCREEN_HEIGHT),
                      SerGUI::WINDOW_TITLE,sf::Style::Default);
        return true;
    }
    void Free()
    {

    }
}

