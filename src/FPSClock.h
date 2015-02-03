#ifndef FPSCLOCK_H
#define FPSCLOCK_H

#include <SFML/System.hpp>

class FPSClock : public sf::Clock
{
	public:
		FPSClock(unsigned int fps);
		virtual ~FPSClock();

		sf::Time restart();
		unsigned int GetElapsedFrames(void) const;

	private:
		unsigned int fps;
		sf::Int32 carryTime;
		unsigned int carryFrame;
};

#endif

