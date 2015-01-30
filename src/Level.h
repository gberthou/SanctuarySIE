#ifndef LEVEL_H
#define LEVEL_H

class Level
{
	public:
		Level(unsigned int width1, unsigned int height1, unsigned int x1, unsigned int y1);
		virtual ~Level();
	
	private:
		unsigned int width;
		unsigned int height;
		unsigned int x;
		unsigned int y;
};

#endif

