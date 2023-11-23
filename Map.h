#pragma once

#include <vector>
#include "SFML\Graphics\RectangleShape.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

using namespace std;

class Map
{

private:


public:
	Map();
	~Map();

	//void placeTower(int x, int y);
	vector<pair<int, int>> interactableCells;
	//std::vector<Tower> towers;

	vector<sf::RectangleShape*> shapes;
	vector<vector<int>> map;
	int getCellSize() const;
	void initializeInteractableCells();
	bool isInteractable(int x, int y) const;
	bool isValidCell(int x, int y) const;
	vector<pair<int, int>> getInteractableCells() const;

};
