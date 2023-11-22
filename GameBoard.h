#pragma once


#include <SFML/Graphics.hpp>
#include <vector>

class GameBoard {
public:
    GameBoard(int rows, int cols, int cellSize);

    void draw(sf::RenderWindow& window) const;
    void placeTower(int x, int y);
    int getCellSize() const ;


    void setInteractableCells(const std::vector<sf::Vector2i>& interactableCells);
    bool isInteractable(int x, int y) const;
    

private:
    void initializeGrid();
    bool isValidCell(int x, int y) const;

    int rows;
    int cols;
    int cellSize;
    std::vector<std::vector<int>> grid; // 2D array representing the game board
};

