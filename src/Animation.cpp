#include "Animation.h"

Animation::Animation(unsigned int startFrame1, unsigned int endFrame1, unsigned int fps1):
	startFrame(startFrame1),
	endFrame(endFrame1),
	fps(fps1),
	playing(false),
	timeCarry(0)
{
}

Animation::~Animation()
{
}

void Animation::Start(unsigned int frame)
{
	currentFrame = (frame < endFrame ? frame : 0);
	playing = true;
	clock.restart();
}

void Animation::Stop(void)
{
	playing = false;
}

void Animation::Update(void)
{
	if(playing)
	{
		sf::Int32 dt = clock.getElapsedTime().asMilliseconds();
		int nframes = dt * fps / 1000;

		if(nframes > 0)
		{
			clock.restart();
			timeCarry += dt - nframes * 1000 / fps;
			nframes += timeCarry * fps / 1000;
			timeCarry %= 1000 / fps;
			
			currentFrame = startFrame + ((currentFrame - startFrame + nframes) % (endFrame - startFrame + 1));
		}
	}
}

bool Animation::IsPlaying(void) const
{
	return playing;
}

unsigned int Animation::GetFrame(void) const
{
	return currentFrame;
}

