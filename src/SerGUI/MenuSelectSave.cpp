#include "MenuSelectSave.h"
#include "Utils.h"
#include <iostream>

sf::Color MenuSelectSave::blue = sf::Color(8,8,176);
unsigned int MenuSelectSave::NB_ACTION = 2;
enum State {CHOICE_NB_STATE, CHOICE_ACTION};

static const char* S_BUTTON_SAVE("img/sergui/maimenu_element1.png");
static const char* S_BUTTON_SAVE_SELECTED("img/sergui/maimenu_element1_select.png");
static const char* S_BUTTON_ACTION("img/sergui/maimenu_element2.png");
static const char* S_BUTTON_ACTION_SELECTED("img/sergui/maimenu_element2_select.png");
static const char* TXT_MENU_TITLE_SAVE("Save");
static const char* TXT_MENU_TITLE_PLAY("Play");
static const char* TXT_MENU_TITLE_ERASE("Erase");
static const char* TXT_MENU_TITLE_COPY("Copy");

MenuSelectSave::MenuSelectSave():
      selected(0), state(CHOICE_NB_STATE), endMenu(false)
{
}

bool MenuSelectSave::Load()
{
    if(!texMenuSelectSaveButtonNbSave
                .loadFromFile(S_BUTTON_SAVE))
    {
        #ifdef DEBUG
        std::cout<<"Fail while loading resource (S_BUTTON_SAVE)"<<std::endl;
        #endif
        return false;
    }
    if(!texMenuSelectSaveButtonNbSaveSelected
            .loadFromFile(S_BUTTON_SAVE_SELECTED))
    {
        #ifdef DEBUG
        std::cout<<"Fail while loading resource (S_BUTTON_SAVE_SELECTED)"<<std::endl;
        #endif
        return false;
    }
    if(!texMenuSelectSaveButtonAction
            .loadFromFile(S_BUTTON_ACTION))
    {
        #ifdef DEBUG
        std::cout<<"Fail while loading resource (S_BUTTON_ACTION)"<<std::endl;
        #endif
        return false;
    }
    if(!texMenuSelectSaveButtonActionSelected
            .loadFromFile(S_BUTTON_ACTION_SELECTED))
    {
        #ifdef DEBUG
        std::cout<<"Fail while loading resource (S_BUTTON_ACTION_SELECTED)"<<std::endl;
        #endif
        return false;
    }
    return true;
}

void MenuSelectSave::init()
{
    for(unsigned int i=0;i<NB_SAVE;++i)
    {
        buttonsNbSave[i].SetTextureDefault(&texMenuSelectSaveButtonNbSave);
        buttonsNbSave[i].SetTextureSelected(&texMenuSelectSaveButtonNbSaveSelected);
        buttonsNbSave[i].SetFont(SerGUI::fontMenu1,36);
        buttonsNbSave[i].SetText(TXT_MENU_TITLE_SAVE+ttos(i+1));
        buttonsNbSave[i].SetPosition(
                (int)(SerGUI::window.getSize().x*1.f/4.f),
                (int)(SerGUI::window.getSize().y*1.f/8.f+100.f*i));
    }
    for(unsigned int i=0;i<NB_ACTION;++i)
    {
        buttonsAction[i].SetTextureDefault(&texMenuSelectSaveButtonAction);
        buttonsAction[i].SetTextureSelected(&texMenuSelectSaveButtonActionSelected);
        buttonsAction[i].SetFont(SerGUI::fontMenu1,36);
    }
    buttonsAction[0].SetText(TXT_MENU_TITLE_PLAY);
    buttonsAction[1].SetText(TXT_MENU_TITLE_ERASE);
    //buttonsAction[2].SetText(SerGUI::TXT_MENU_TITLE_COPY);
    for(unsigned int i=0;i<NB_ACTION;++i)
    {
        buttonsAction[i].SetPosition(
                (int)(SerGUI::window.getSize().x*3.f/4.f),
                (int)(SerGUI::window.getSize().y*1.f/8.f+100.f*i));
    }
    changeState(state);
}

void MenuSelectSave::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(unsigned int i=0;i<NB_SAVE;++i)
    {
        target.draw(buttonsNbSave[i]);
    }
    for(unsigned int i=0;i<NB_ACTION;++i)
    {
        target.draw(buttonsAction[i]);
    }
}

bool MenuSelectSave::Run()
{
    init();
	while(SerGUI::window.isOpen() && !endMenu)
	{
		sf::Event event;
		while(SerGUI::window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				SerGUI::window.close();
            if(event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                    SerGUI::window.close();
            }
            manageEvent(event);
		}

		SerGUI::window.clear(blue);
		SerGUI::window.draw(*this);

		SerGUI::window.display();
	}
	return true;
}

void MenuSelectSave::manageEvent(sf::Event const& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == keys_mapping[KEY_UP])
        {
            --selected;
            changeSelection();
        }
        else if (event.key.code == keys_mapping[KEY_DOWN])
        {
            ++selected;
            changeSelection();
        }
        else if (event.key.code == keys_mapping[KEY_A]
            || event.key.code == keys_mapping[KEY_START])
        {
            switch(state)
            {
                case CHOICE_NB_STATE:
                    saveSelected = selected;
                    selected = 0;
                    changeState(CHOICE_ACTION);
                    break;
                case CHOICE_ACTION:
                    executeAction();
                    break;
                default: ;
            }
        }
        else if (event.key.code == keys_mapping[KEY_B])
        {
            switch(state)
            {
                case CHOICE_NB_STATE:
                    endMenu = true;
                    break;
                case CHOICE_ACTION:
                    selected = saveSelected;
                    saveSelected = -1;
                    changeState(CHOICE_NB_STATE);
                    break;
                default: ;
            }
        }
    }
}

void MenuSelectSave::executeAction()
{
    switch(selected)
    {
        case 0:
            play();
            break;
        case 1:
            deleteSave();
            break;
        default:;
    }
}

void MenuSelectSave::changeState(int nstate)
{
    state = nstate;
    for(unsigned int i=0;i<NB_SAVE;++i)
    {
        buttonsNbSave[i].Unselect();
        if((int)i != saveSelected)
        {
            buttonsNbSave[i].Lock();
        }

        if(state == CHOICE_NB_STATE)
        {
            buttonsNbSave[i].Unlock();
        }
    }
    for(unsigned int i=0;i<NB_ACTION;++i){
        buttonsAction[i].Unselect();
        if(state != CHOICE_ACTION)
        {
            buttonsAction[i].Lock();
        }
        else
        {
             buttonsAction[i].Unlock();
        }
    }
    changeSelection();
}

void MenuSelectSave::changeSelection()
{
    if(state == CHOICE_NB_STATE)
    {
        if(selected < 0)
        {
            selected = NB_SAVE-1;
        }
        else if(selected >= (int)NB_SAVE)
        {
            selected = 0;
        }
        for(unsigned int i=0;i<NB_SAVE;++i)
        {
            buttonsNbSave[i].Unselect();
        }
        buttonsNbSave[selected].Select();
    }
    if(state == CHOICE_ACTION)
    {
        if(selected < 0)
        {
            selected = NB_ACTION-1;
        }
        else if(selected >= (int)NB_ACTION)
        {
            selected = 0;
        }
        for(unsigned int i=0;i<NB_ACTION;++i)
            buttonsAction[i].Unselect();
        buttonsAction[selected].Select();
    }
}

void MenuSelectSave::play()
{
    // save chosen:
    // saveSelected
}

void MenuSelectSave::deleteSave()
{
    // save chosen:
    // saveSelected
}
