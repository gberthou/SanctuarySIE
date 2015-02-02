#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/System.hpp>

class Animation
{
	public:
		Animation(unsigned int startFrame, unsigned int endFrame, unsigned int fps);
		virtual ~Animation();

		void Start(unsigned int frame);
		void Stop(void);
		void Update(void);

		bool IsPlaying(void) const;
		unsigned int GetFrame(void) const;

	private:
		unsigned int currentFrame;
		unsigned int startFrame;
		unsigned int endFrame;
		unsigned int fps;
		bool playing;
		sf::Clock clock;
		sf::Int32 timeCarry;
};

#endif

