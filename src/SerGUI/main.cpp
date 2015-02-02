#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "MenuTitle1.h"
#include "SerGUI.h"
#include "Resources.h"

int main()
{
	Resources::Load();
    SerGUI::Load();
    MenuTitle1 menu;
    menu.Run();
	return 0;
}

