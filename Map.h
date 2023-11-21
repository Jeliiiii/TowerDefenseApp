#pragma once

#include <vector>
#include "SFML\Graphics\RectangleShape.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

class Map
{
	std::vector<std::vector<int>> map;
	std::vector<sf::RectangleShape*> shapes;


	public:
		Map();
		~Map();

		void draw(sf::RenderWindow& window);
};