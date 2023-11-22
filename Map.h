#pragma once

#include <vector>
#include "SFML\Graphics\RectangleShape.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Path.h"

class Map
{
	std::vector<std::vector<int>> map;
	std::vector<sf::RectangleShape*> shapes;

	Path* path;


	public:
		Map(const char* name);
		~Map();

		void draw(sf::RenderWindow& window);
};