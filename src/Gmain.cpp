#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Resources.h"
#include "Map.h"
#include "Character.h"
#include "LevelBg.h"
#include "MobFactory.h"
#include "LevelFactory.h"
#include "FPSClock.h"
#include "InputController.h"
#include "ItemFactory.h"
#include "ItemType.h"
#include "SoulSet.h"
#include "SoulManager.h"
#include "Camera.h"
#include "BoxExpandable.h"
#include "SerGUI.h"
#include "UICharacterStatus.h"

int main(void)
{
	FPSClock clock(60);
	Map *map;
	Character *character;
	Inventory *inventory;
	SoulSet *soulSet;
	InputController *inputController;
	UICharacterStatus *uicharacterstatus;
	Weapon *dagger = ItemFactory::CreateWeapon(DAGGER);

	if(!Resources::Load())
	{
		// :(
	}
	
	if(!SerGUI::Load())
	{
		// :(
	}
	
	LevelFactory::CreateDoors();
	SoulManager::Init();

	map = new Map();
	map->Load();

	character = new Character(new Stats(10,6,10,12,11,9),320,(unsigned int)a_EXP + b_EXP + c_EXP);

    inputController = new InputController(character);
	//inputController->SetEventSource(ES_JOYSTICK);
    
	uicharacterstatus = new UICharacterStatus(character);
    
	if(!uicharacterstatus->Load())
	{
		// :(
	}

	// Simulate save loading
	map->SetCurrentLevel(CORRIDOR0);

	// Simulate the arrival of the player in the map
	map->MakeCurrentLevelReady(character);

	inventory = character->GetInventory();
	inventory->LootItem(dagger);
	inventory->EquipWeapon(inventory->GetWeapons().begin());

	soulSet = character->GetSoulSet();
	soulSet->AddSoul(SoulManager::GetSoul(GIANT_BAT)); // Red soul
	soulSet->EquipRedSoul(soulSet->GetRedSouls().begin());
	soulSet->AddSoul(SoulManager::GetSoul(DEATH)); // Blue soul
	soulSet->EquipBlueSoul(soulSet->GetBlueSouls().begin());
    
    // View management
    Camera camera(sf::FloatRect(0, 0, SerGUI::SCREEN_WIDTH, SerGUI::SCREEN_HEIGHT));
	SerGUI::window.setView(camera);
    
    // a box with text
    BoxExpandable box = BoxExpandable();
    box.SetDefaultTexture();
    box.SetRect(sf::IntRect(10,500,780,100));
    box.SetTextPositionOffset(sf::Vector2f(-70.0f,-20.0f));
    box.SetTextAuto("Lorem ipsum dolor sit amet, consectetur adipiscing elit. \
Suspendisse vel sagittis mauris. \
Nullam imperdiet ex purus, nec dictum lacus tempus in.");

	while(SerGUI::window.isOpen())
	{
		unsigned int frameCount;
		sf::Event event;

		while(SerGUI::window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				SerGUI::window.close();

			inputController->Update();
		}

		frameCount = clock.GetElapsedFrames();
		if(frameCount > 0)
		{
			clock.restart();

			SerGUI::window.clear(sf::Color::Black);

			map->DrawCurrentLevel(SerGUI::window, sf::RenderStates());
			
			SerGUI::window.setView(SerGUI::window.getDefaultView());
			SerGUI::window.draw(box);
			SerGUI::window.draw(*uicharacterstatus);
			
			SerGUI::window.display();
            
            // View management
            camera.Update(map->GetCurrentLevel(), character);
            SerGUI::window.setView(camera);
            
			map->Update(character, frameCount);
		}
	}

	delete map;
	delete character;
	delete inputController;
	delete uicharacterstatus;
	SoulManager::Free();
	LevelFactory::FreeDoors();

	return 0;
}

