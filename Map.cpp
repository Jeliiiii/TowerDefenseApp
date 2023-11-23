#include "Map.h"

Map::Map(const char* name)
{
	for (int i = 0; i < 16; i++)
	{
		std::vector<int> t;
		for (int j = 0; j < 9; j++)
		{
				t.push_back(0);
		}
		map.push_back(t);
	}

	if (name == "testmap")
	{
		map[1][0] = 1;
		map[1][1] = 1;
		map[1][2] = 1;
		map[1][3] = 1;
		map[1][4] = 1;
		map[2][4] = 1;
		map[3][4] = 1;
		map[3][3] = 1;
		map[3][2] = 1;
		map[4][2] = 1;
		map[5][2] = 1;
		map[6][2] = 1;
		map[6][3] = 1;
		map[6][4] = 1;
		map[6][5] = 1;
		map[5][5] = 1;
		map[5][6] = 1;
		map[5][7] = 1;
		map[6][7] = 1;
		map[7][7] = 1;
		map[8][7] = 1;
		map[9][7] = 1;
		map[9][6] = 1;
		map[9][5] = 1;
		map[9][4] = 1;
		map[9][3] = 1;
		map[10][3] = 1;
		map[11][3] = 1;
		map[12][3] = 1;
		map[13][3] = 1;
		map[14][3] = 1;
		map[14][4] = 1;
		map[14][5] = 1;
		map[15][5] = 1;
		//map[map.size() - 1][2] = 1;
	}
	else {
		throw std::invalid_argument("No map with the given name exists.");
	}

	path = new Path(name);

	sf::RectangleShape* get_some_help;
	for (int i = 0; i < 16+9; i++)
	{
		get_some_help = new sf::RectangleShape(sf::Vector2f(80, 80));
		shapes.push_back(get_some_help);
	}
}

Map::~Map()
{
	for (int i = 0; i < shapes.size(); i++)
	{
		delete shapes[i];
	}
}

void Map::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			shapes[i + j]->setPosition(80 * i, 80 * j);
			if (map[i][j] == 0)
				shapes[i + j]->setFillColor(sf::Color(50, 200, 10, 255));
			else if (map[i][j] == 1)
				shapes[i + j]->setFillColor(sf::Color(175, 100, 0, 255));
			shapes[i + j]->setOutlineColor(sf::Color::Black);
			shapes[i + j]->setOutlineThickness(1);
			for (int i2 = 0; i2 < path->points.size(); i2++)
			{
				//if (path->points[i2].x == i && path->points[i2].y == j)
					//shapes[i + j]->setFillColor(sf::Color(255, 0, 0, 255));
			}
			window.draw(*shapes[i + j]);
		}
	}
}