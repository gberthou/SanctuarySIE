#ifndef PATH_H
#define PATH_H

#include <vector>

#include <SFML/System.hpp>

typedef std::vector<sf::Vector2f> PathMarker;

class Path
{
	public:
		Path();
		virtual ~Path();

		void AddPosition(sf::Vector2f position);
		void Ready(void);
		sf::Vector2f GetNextPosition(void) const;

	private:
		PathMarker positions;
		PathMarker::const_iterator next;
};

#endif

