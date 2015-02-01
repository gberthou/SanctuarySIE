#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "MenuTitle.h"
#include "SerGUI.h"
#include "Resources.h"

int main()
{
	Resources::Load();
    SerGUI::Load();
    MenuTitle menu = MenuTitle();
    menu.Run();
	return 0;
}

