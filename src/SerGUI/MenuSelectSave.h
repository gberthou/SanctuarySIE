#ifndef MENU_SELECT_SAVE
#define MENU_SELECT_SAVE

#include "SerGUI.h"
#include "InputController.h"
#include "Button.h"

#include <SFML/Graphics.hpp>

/** The second menu of the game : manage saves */
class MenuSelectSave : public sf::Drawable
{
    public:
        MenuSelectSave();
        bool Run();

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        bool Load();
    protected:
        void init();
        void changeState(int newState);
        void changeSelection();
        void play();
        void deleteSave();
        void executeAction();
        void manageEvent(sf::Event const& e);

        //sf::Sprite buttons[NB_SAVE];
        //sf::Text buttonsText[NB_SAVE];
        Button buttonsNbSave[NB_SAVE];
        Button buttonsAction[2];
        int selected;
        int saveSelected;
        int actionSelected;
        int state;
        bool endMenu;

        static unsigned int NB_ACTION;
        static sf::Color blue;

        sf::Texture texMenuSelectSaveButtonNbSave;
        sf::Texture texMenuSelectSaveButtonNbSaveSelected;
        sf::Texture texMenuSelectSaveButtonAction;
        sf::Texture texMenuSelectSaveButtonActionSelected;
};

#endif // MENU_SELECT_SAVE
