#ifndef AABB_H
#define AABB_H

#include <SFML/System.hpp>

class AABB
{
	public:
		AABB();
		AABB(const sf::Vector2f &size);
		AABB(const sf::Vector2f &position, const sf::Vector2f &size);
		AABB(const AABB &other);
		virtual ~AABB();
	
		bool CollidesWith(const AABB &box) const;
		bool CollidesWith(const sf::Vector2f &point) const;

		void SetPosition(const sf::Vector2f &position);
		void SetSize(const sf::Vector2f &size);

		sf::Vector2f GetPosition(void) const;
		sf::Vector2f GetCenter(void) const;
		sf::Vector2f GetSize(void) const;

	protected:
		sf::Vector2f pos;
		sf::Vector2f size;
		
		friend class Physics;
};

#endif

