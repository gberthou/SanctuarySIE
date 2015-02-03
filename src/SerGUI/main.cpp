#include <cstdlib>
#include <ctime>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "MenuTitle1.h"
#include "MenuSelectSave.h"
#include "SerGUI.h"
#include "Resources.h"

int main()
{
	MenuTitle1Code code;

	srand(time(0));

	Resources::Load();
    SerGUI::Load();

	do
	{
		MenuTitle1 *menuTitle = new MenuTitle1();
		MenuSelectSave *menuSelectSave;
		
		menuTitle->Load();
		code = menuTitle->Run();
		delete menuTitle;

		menuSelectSave = new MenuSelectSave();
		menuSelectSave->Run();
		delete menuSelectSave;

	}while(code != EXIT);
	
	return 0;
}

