#include "Path.h"

Path::Path(const char* name)
{
	if (name == "testmap")
	{
		points.push_back(sf::Vector2i(1, 0));
		points.push_back(sf::Vector2i(1, 4));
		points.push_back(sf::Vector2i(3, 4));
		points.push_back(sf::Vector2i(3, 2));
		points.push_back(sf::Vector2i(6, 2));
		points.push_back(sf::Vector2i(6, 5));
		points.push_back(sf::Vector2i(5, 5));
		points.push_back(sf::Vector2i(5, 7));
		points.push_back(sf::Vector2i(9, 7));
		points.push_back(sf::Vector2i(9, 3));
		points.push_back(sf::Vector2i(14, 3));
		points.push_back(sf::Vector2i(14, 5));
		points.push_back(sf::Vector2i(16, 5));
	}
}