#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/System.hpp>

#include "FPSClock.h"

enum AnimationMode
{
	AM_CYCLE,
	AM_ONCE
};

class Animation
{
	public:
		Animation(unsigned int startFrame, unsigned int endFrame, unsigned int fps, AnimationMode mode);
		virtual ~Animation();

		void Start(unsigned int frame);
		void Stop(void);
		void Update(void);

		bool IsPlaying(void) const;
		unsigned int GetFrame(void) const;

	protected:
		Animation(unsigned int fps);

		unsigned int currentFrame;
		unsigned int startFrame;
		unsigned int endFrame;
		AnimationMode mode;
		bool playing;
		FPSClock clock;
};

#endif

