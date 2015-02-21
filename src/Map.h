#ifndef MAP_H
#define MAP_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "Level.h"

struct LevelConnection
{
	LevelConnection(Level *l1, Level *l2):
		level1(l1),
		level2(l2)
	{
	}

	Level *level1;
	Level *level2;
};

class Map : public sf::Drawable
{
	public:
		Map();
		virtual ~Map();
	
		void Load(void);
		void SetCurrentLevel(IdLevel idLevel);

		void MakeCurrentLevelReady(Character *character);
		void Update(Character *character, unsigned int frameCount);

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
		void DrawCurrentLevel(sf::RenderTarget &target, sf::RenderStates states) const;

		Level *GetCurrentLevel(void) const;
		IdLevel GetCurrentLevelId(void) const;

	private:
		static void drawLevelDoors(Level *level, sf::RenderTarget &target, sf::RenderStates states);

		std::vector<Level*> levels;
		Level *currentLevel;
		IdLevel currentLevelId;
};

#endif

