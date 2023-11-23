
#include "Map.h"
#include <iostream>

using namespace std;

Map::Map()
{
	for (int i = 0; i < 16; i++)
	{
		vector<int> t;
		for (int j = 0; j < 9; j++)
		{
			t.push_back(0);
		}
		map.push_back(t);
	}

	//Chemin de deplacement des ennemis
	map[1][0] = 1;
	map[1][1] = 1;
	map[1][2] = 1;
	map[1][3] = 1;
	map[1][4] = 1;
	map[2][4] = 1;
	map[3][4] = 1;
	map[3][3] = 1;
	map[3][2] = 1;
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

	initializeInteractableCells();

	sf::RectangleShape* cellMap;
	for (int i = 0; i < 20 + 24; i++)
	{
		cellMap = new sf::RectangleShape(sf::Vector2f(80, 80));
		shapes.push_back(cellMap);
	}
}

Map::~Map()
{
	for (int i = 0; i < 20 + 24; i++)
	{
		delete shapes[i];
	}
}

void Map::initializeInteractableCells()
{

	map[2][3] = 3;
	map[0][1] = 3;
	map[5][3] = 3;
	map[0][4] = 3;
	map[4][5] = 3;
	map[5][8] = 3;
	map[8][6] = 3;
	map[5][8] = 3;
	map[10][4] = 3;
	map[13][4] = 3;
	map[15][4] = 3;
	map[7][4] = 3;

}

bool Map::isInteractable(int x, int y) const
{
	if (isValidCell(x, y)) {
		return map[x][y] == 3;
	}
	return false;
}

bool Map::isValidCell(int x, int y) const
{
	return x >= 0 && x < map.size() && y >= 0 && y < map[0].size();
}

vector<pair<int, int>> Map::getInteractableCells() const
{
	return interactableCells;
}

int Map::getCellSize() const
{
	int cell = 80;
	return cell;
}