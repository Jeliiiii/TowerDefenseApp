
#include "Map.h"

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
	//map[map.size() - 1][2] = 1;

	initializeInteractableCells();

	sf::RectangleShape* get_some_help;
	for (int i = 0; i < 20 + 24; i++)
	{
		get_some_help = new sf::RectangleShape(sf::Vector2f(80, 80));
		shapes.push_back(get_some_help);
	}
}

Map::~Map()
{
	for (int i = 0; i < 20 + 24; i++)
	{
		delete shapes[i];
	}
}

void Map::draw(sf::RenderWindow& window) {
	int cellSize = getCellSize();
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			shapes[i + j]->setPosition(cellSize * i, cellSize * j);

			if (map[i][j] == 0) {
				shapes[i + j]->setFillColor(sf::Color::Green); // Empty cell
			}
			else if (map[i][j] == 1) {
				shapes[i + j]->setFillColor(sf::Color(175, 100, 0, 255)); // Path cell
			}
			else if (map[i][j] == 2) {
				shapes[i + j]->setFillColor(sf::Color::Magenta); // Tower cell
			}

			// Check if the cell is interactable and set the color
			if (isInteractable(i, j)) {
				shapes[i + j]->setFillColor(sf::Color::Blue); // Interactable cell
			}

			shapes[i + j]->setOutlineColor(sf::Color::Black);
			shapes[i + j]->setOutlineThickness(1);
			window.draw(*shapes[i + j]);
		}
	}
}

void Map::initializeInteractableCells()
{

	setInteractableCell(5, 0);
	setInteractableCell(6, 0);
	setInteractableCell(7, 0);

}

void Map::setInteractableCell(int x, int y)
{
	if (isValidCell(x, y))
	{
		interactableCells.push_back({ x, y });
	}
}

bool Map::isInteractable(int x, int y) const
{
	if (isValidCell(x, y)) {
		return map[x][y] != 1 && map[x][y] != 2;
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

void Map::placeTower(int x, int y) {
	if (isValidCell(x, y) && isInteractable(x, y)) {
		Tower tower(sf::Vector2f(x * getCellSize(), y * getCellSize())); // Create a tower at the specified position
		towers.push_back(tower);
	}
}