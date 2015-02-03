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

const float SPEED_MIN = 1.f;
const float SPEED_MAX = 3.f;

const float ROTATION_MIN = -10;
const float ROTATION_MAX = 10;

const float OBJECTIVE_EPSILON = 4;
const unsigned int OBJECTIVE_SPAWN_DIST = 100;

const sf::IntRect SPAWN_AREA(125, 458, 627-125, 100);

const float VELOCITY = 1.5f;

const unsigned int OUT_Y = 388;

static float max(float x, float y)
{
	return x > y ? x : y;
}

static float min(float x, float y)
{
	return x < y ? x : y;
}

Bat::Bat(const sf::Texture &texture):
	sf::Drawable(),
	sprite(texture),
	animation(0, FRAME_NUMBER-1, FPS),
	outside(false)
{
	int x = SPAWN_AREA.left + (rand() % (SPAWN_AREA.width + 1));
	int y = SPAWN_AREA.top + (rand() % (SPAWN_AREA.height + 1));

	float rotation = ROTATION_MIN + rand() * (ROTATION_MAX - ROTATION_MIN) / RAND_MAX;

	pos = sf::Vector2f(x, y);
	objective = sf::Vector2f(x, y - 200);
	
	scale = SCALE_MIN + rand() * (SCALE_MAX - SCALE_MIN) / RAND_MAX;
	sprite.setOrigin(sf::Vector2f(FRAME_WIDTH, FRAME_HEIGHT) * scale/2.f);
	sprite.setRotation(rotation);	
	sprite.setScale(scale, scale);

	birth = rand() % BIRTH_MAX;
	
	speed = (SPEED_MIN + rand() * (SPEED_MAX-SPEED_MIN) / RAND_MAX) * VELOCITY;
}

Bat::~Bat()
{
}

void Bat::Update(unsigned int frameCount)
{

	if(!animation.IsPlaying())
	{
		animation.Start(rand() % FRAME_NUMBER);
		clock.restart();
	}
	
	if(isBorn())
	{
		sf::Vector2f diff = objective - pos;

		if(pos.y <= OUT_Y)
			outside = true;

		if(diff.x * diff.x + diff.y * diff.y <= 1)
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
				pos.x += min(diff.x, speed * frameCount);
				sprite.setScale(scale, scale);
			}
			else if(diff.x < 0)
			{
				pos.x += max(diff.x, -speed * frameCount);
				sprite.setScale(-scale, scale);
			}

			if(diff.y > 0) // Objective below
			{
				pos.y += min(diff.y, speed * frameCount);
			}
			else if(diff.y < 0)
			{
				pos.y += max(diff.y, -speed * frameCount);
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

bool Bat::IsOutside(void) const
{
	return outside;
}

bool Bat::isBorn(void) const
{
	return animation.IsPlaying() && clock.getElapsedTime().asMilliseconds() >= birth;
}

