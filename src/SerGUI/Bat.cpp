#include <cstdlib>

#include "Bat.h"
#include "SerGUI.h"

const unsigned int FRAME_WIDTH = 200;
const unsigned int FRAME_HEIGHT = 100;
const unsigned int FRAME_NUMBER = 3;
const unsigned int FPS = 10;

const unsigned int BIRTH_MAX = 4000;

const float SCALE_MIN = 0.2f;
const float SCALE_MAX = 0.6f;

const float ROTATION_MIN = -10;
const float ROTATION_MAX = 10;

const float OBJECTIVE_EPSILON = 4;
const unsigned int OBJECTIVE_SPAWN_DIST = 100;

const sf::IntRect SPAWN_AREA(100, 400, 600, 100);

const float VELOCITY = 4;

Bat::Bat(const sf::Texture &texture):
	sf::Drawable(),
	sprite(texture),
	animation(0, FRAME_NUMBER-1, FPS)
{
	int x = SPAWN_AREA.left + (rand() % (SPAWN_AREA.width + 1));
	int y = SPAWN_AREA.top + (rand() % (SPAWN_AREA.height + 1));

	float rotation = ROTATION_MIN + rand() * (ROTATION_MAX - ROTATION_MIN) / RAND_MAX;

	pos = sf::Vector2f(x, y);
	objective = pos;
	
	scale = SCALE_MIN + rand() * (SCALE_MAX - SCALE_MIN) / RAND_MAX;
	sprite.setOrigin(sf::Vector2f(FRAME_WIDTH, FRAME_HEIGHT) * scale/2.f);
	sprite.setRotation(rotation);	
	sprite.setScale(scale, scale);

	birth = rand() % BIRTH_MAX;
}

Bat::~Bat()
{
}

void Bat::Update(void)
{

	if(!animation.IsPlaying())
	{
		animation.Start(rand() % FRAME_NUMBER);
		clock.restart();
	}
	
	if(isBorn())
	{
		sf::Vector2f diff = objective - pos;

		if(diff.x * diff.x + diff.y * diff.y < OBJECTIVE_EPSILON)
		{
			int dx = (rand() % (2 * OBJECTIVE_SPAWN_DIST + 1)) - OBJECTIVE_SPAWN_DIST;
			int dy = (rand() % (2 * OBJECTIVE_SPAWN_DIST + 1)) - OBJECTIVE_SPAWN_DIST;
			objective = pos + sf::Vector2f(dx, dy);
			
			if(objective.x < 0)
				objective.x = 0;
			else if(objective.x >= SerGUI::SCREEN_WIDTH)
				objective.x = SerGUI::SCREEN_WIDTH - OBJECTIVE_SPAWN_DIST;

			if(objective.y < 0)
				objective.y = 0;
			else if(objective.y >= SerGUI::SCREEN_HEIGHT)
				objective.y = SerGUI::SCREEN_HEIGHT - OBJECTIVE_SPAWN_DIST;
		}
		else
		{
			if(diff.x > 0) // Objective on the right
			{
				pos.x += 1.f;
				sprite.setScale(scale, scale);
			}
			else if(diff.x < 0)
			{
				pos.x -= 1.f;
				sprite.setScale(-scale, scale);
			}

			if(diff.y > 0) // Objective below
			{
				pos.y += 1.f;
			}
			else if(diff.y < 0)
			{
				pos.y -= 1.f;
			}
		}

	}

	sprite.setTextureRect(sf::IntRect(FRAME_WIDTH * animation.GetFrame(), 0, FRAME_WIDTH, FRAME_HEIGHT));
	sprite.setPosition(pos);
	animation.Update();
}

void Bat::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if(isBorn())
		target.draw(sprite, states);
}

bool Bat::isBorn(void) const
{
	return animation.IsPlaying() && clock.getElapsedTime().asMilliseconds() >= birth;
}

