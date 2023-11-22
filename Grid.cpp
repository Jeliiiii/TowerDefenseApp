#include "Grid.h"
#include <iostream>

GameBoard::GameBoard(int rows, int cols, int cellSize)
    : rows(rows), cols(cols), cellSize(cellSize) {
    initializeGrid();
}

void GameBoard::draw(sf::RenderWindow& window) const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
            cell.setPosition(i * cellSize, j * cellSize);

            // Customize cell appearance based on grid values
            if (grid[i][j] == 1) {
                cell.setFillColor(sf::Color::Green); // Tower
            }
            else {
                cell.setFillColor(sf::Color::White); // Empty
            }

            cell.setOutlineColor(sf::Color::Black); // Outline color
            cell.setOutlineThickness(1.0f); // Outline thickness

            window.draw(cell);
        }
    }
}

void GameBoard::placeTower(int x, int y) {
    if (isValidCell(x, y)) {
        grid[x][y] = 1; // Place tower
    }
}

void GameBoard::initializeGrid() {
    grid.resize(rows, std::vector<int>(cols, 0)); // Initialize with zeros
}

bool GameBoard::isValidCell(int x, int y) const {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

int GameBoard::getCellSize() {
	return cellSize;
}