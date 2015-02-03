#include "FPSClock.h"

FPSClock::FPSClock(unsigned int fps1):
	fps(fps1),
	carryTime(0),
	carryFrame(0)
{
}

FPSClock::~FPSClock()
{
}

sf::Time FPSClock::restart()
{
	unsigned int invMs = 1000 / fps;

	carryTime += getElapsedTime().asMilliseconds() % invMs;
	carryFrame = carryTime / invMs;
	carryTime -= carryFrame * invMs;

	return sf::Clock::restart();
}

unsigned int FPSClock::GetElapsedFrames(void) const
{
	return (getElapsedTime().asMilliseconds() + carryTime) * fps / 1000 + carryFrame;

}

