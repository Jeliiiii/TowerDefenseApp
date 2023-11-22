#include <SFML/Graphics.hpp>
#include "GameBoard.h"
#include "Enemy.h"

#include <iostream>

int main() {
    const int rows = 10;
    const int cols = 10;
    const int cellSize = 50;

    sf::RenderWindow window(sf::VideoMode(rows * cellSize, cols * cellSize), "Tower Defense Game");

    GameBoard gameBoard(rows, cols, cellSize);

    // Example: Create an enemy with a predefined path
    

    //GAME LOOP

    std::vector<sf::Vector2i> interactableCells = { {0, 0}, {7, 0}, {0, 7}, {5,5}, {3,3}, {6,8} };
    gameBoard.setInteractableCells(interactableCells);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
				// Handle keyboard input
                if (event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
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
        /*enemy.move();*/
        /*enemy.draw(window);*/

        window.display();
    }

    return 0;
}
