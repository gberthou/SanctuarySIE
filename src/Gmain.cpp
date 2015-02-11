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

int main(void)
{
	const unsigned int W = 800;
	const unsigned int H = 600;

	sf::RenderWindow window(sf::VideoMode(W, H), "Sample");
	FPSClock clock(60);
	Level *level;
	Character *character;
	Inventory *inventory;
	SoulSet *soulSet;
	InputController *inputController;
	Weapon *dagger = ItemFactory::CreateWeapon(DAGGER);

	Resources::Load();
	SoulManager::Init();

	level = LevelFactory::CreateLevel(CORRIDOR0);
	character = new Character();

    inputController = new InputController(character);
	//inputController->SetEventSource(ES_JOYSTICK);

	// Simulate the arrival of the player in the level
	level->MakeReady(character);

	inventory = character->GetInventory();
	inventory->LootItem(dagger);
	inventory->EquipWeapon(inventory->GetWeapons().begin());

	soulSet = character->GetSoulSet();
	soulSet->AddSoul(SoulManager::GetSoul(GIANT_BAT)); // Red soul
	soulSet->EquipRedSoul(soulSet->GetRedSouls().begin());
	soulSet->AddSoul(SoulManager::GetSoul(DEATH)); // Blue soul
	soulSet->EquipBlueSoul(soulSet->GetBlueSouls().begin());
    
    // View management
    Camera camera(sf::FloatRect(0, 0, W, H));
    window.setView(camera);

	while(window.isOpen())
	{
		unsigned int frameCount;
		sf::Event event;

		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();

			inputController->Update(event);
		}

		frameCount = clock.GetElapsedFrames();
		if(frameCount > 0)
		{
			clock.restart();

			window.clear(sf::Color::Black);

			window.draw(*level);

			window.display();
            
            // View management
            camera.Update(level, character);
            window.setView(camera);

			level->Update(frameCount);
		}
	}

	delete level;
	delete character;
	delete inputController;

	SoulManager::Free();

	return 0;
}

