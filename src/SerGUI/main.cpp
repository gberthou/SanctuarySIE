#include <cstdlib>
#include <ctime>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "MenuTitle1.h"
#include "SerGUI.h"
#include "Resources.h"

int main()
{
	srand(time(0));

	Resources::Load();
    SerGUI::Load();
    MenuTitle1 menu;
    menu.Load();
	menu.Run();
	return 0;
}

