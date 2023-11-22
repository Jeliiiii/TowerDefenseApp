#pragma once
#include <vector>
#include "SFML/System/Vector2.hpp"

class Path
{
	public:
		std::vector<sf::Vector2i> points;

		Path(const char* name);
};