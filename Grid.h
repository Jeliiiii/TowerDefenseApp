#pragma once
#include <SFML/Graphics.hpp>

class Grid {
public:
    Grid(int numRows, int numCols, sf::RenderWindow& window);
    void handleInput(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    sf::Vector2i getMouseGridPosition(sf::RenderWindow& window);

private:
    int numRows;
    int numCols;
    sf::RenderWindow& window;
};