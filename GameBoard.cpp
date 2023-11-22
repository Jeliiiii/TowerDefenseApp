#include "GameBoard.h"
#include <iostream>

using namespace std;

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
            if (grid[i][j] == 2) {
                cell.setFillColor(sf::Color::Magenta); // Tower
            }
            else {
                cell.setFillColor(sf::Color::Black); // Empty
            }

            cell.setOutlineColor(sf::Color::White); // Outline color
            cell.setOutlineThickness(1.0f); // Outline thickness

            if (isInteractable(i, j)) {
                cell.setFillColor(sf::Color::Blue);
            }

            window.draw(cell);
        }
    }
}

void GameBoard::placeTower(int x, int y) {
    if (isValidCell(x, y) && isInteractable(x, y)) {
        grid[x][y] = 2; // Place tower
    }
}


void GameBoard::initializeGrid() {
    grid.resize(rows, std::vector<int>(cols, 1)); // Initialize with zeros
}

bool GameBoard::isValidCell(int x, int y) const {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

int GameBoard::getCellSize() const{
	return cellSize;
}

void GameBoard::setInteractableCells(const std::vector<sf::Vector2i>& interactableCells) {
    for (const auto& cell : interactableCells) {
        if (isValidCell(cell.x, cell.y)) {
            grid[cell.x][cell.y] = 0;
        }
    }
}


bool GameBoard::isInteractable(int x, int y) const {
    if (isValidCell(x, y)) {
		return grid[x][y] == 0;
	}

	return false;
}

