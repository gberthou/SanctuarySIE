#ifndef LEVEL_H
#define LEVEL_H

class Level
{
	public:
		Level(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
		virtual ~Level();

		unsigned int GetX(void) const;
		unsigned int GetY(void) const;
		unsigned int GetWidth(void) const;
		unsigned int GetHeight(void) const;

	private:
		unsigned int x;
		unsigned int y;
		unsigned int width;
		unsigned int height;
};

#endif

