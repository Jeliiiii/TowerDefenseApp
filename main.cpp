#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Enemy.h"

#include <iostream>

int main() {
    const int rows = 10;
    const int cols = 10;
    const int cellSize = 50;

    sf::RenderWindow window(sf::VideoMode(rows * cellSize, cols * cellSize), "Tower Defense Game");

    GameBoard gameBoard(rows, cols, cellSize);

    // Example: Create an enemy with a predefined path
    std::vector<sf::Vector2i> enemyPath = { {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0} };
    Enemy enemy(enemyPath, 2.0f, cellSize);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Handle mouse click to place towers
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                int cellX = mousePosition.x / cellSize;
                int cellY = mousePosition.y / cellSize;
                gameBoard.placeTower(cellX, cellY);
            }
        }

        window.clear(sf::Color::Black); // Clear the window with black color

        gameBoard.draw(window);

        // Example: Draw and move the enemy
        enemy.move();
        enemy.draw(window);

        window.display();
    }

    return 0;
}
