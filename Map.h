#pragma once

#include <vector>
#include "SFML\Graphics\RectangleShape.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Tower.h"


using namespace std;

class Map
{
	vector<vector<int>> map;
	vector<sf::RectangleShape*> shapes;

	void initializeInteractableCells();
	void setInteractableCell(int x, int y);
	bool isInteractable(int x, int y) const;
	bool isValidCell(int x, int y) const;
	vector<pair<int, int>> getInteractableCells() const;
	
	int getCellSize() const;




	public:
		Map();
		~Map();

		void placeTower(int x, int y);
		void draw(sf::RenderWindow& window);
		vector<pair<int, int>> interactableCells;
		std::vector<Tower> towers;
		
};