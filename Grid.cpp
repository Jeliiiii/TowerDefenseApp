#include "Grid.h"
#include <iostream>

Grid::Grid(int numRows, int numCols, sf::RenderWindow& window) : numRows(numRows), numCols(numCols), window(window) {}

void Grid::handleInput(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        // Handle mouse input for tower placement
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePosition = getMouseGridPosition(window);
                std::cout << "Placed tower at grid position (" << mousePosition.x << ", " << mousePosition.y << ")\n";
            }
        }
    }
}

void Grid::draw(sf::RenderWindow& window) {
    float cellWidth = static_cast<float>(window.getSize().x) / numCols;
    float cellHeight = static_cast<float>(window.getSize().y / 2) / numRows;  // Adjust for bottom half

    // Draw grid lines
    for (int i = 1; i < numRows; ++i) {
        sf::VertexArray horizontalLine(sf::Lines, 2);
        horizontalLine[0].position = sf::Vector2f(0, window.getSize().y / 2 + i * cellHeight);
        horizontalLine[1].position = sf::Vector2f(window.getSize().x, window.getSize().y / 2 + i * cellHeight);
        window.draw(horizontalLine);
    }

    for (int i = 1; i < numCols; ++i) {
        sf::VertexArray verticalLine(sf::Lines, 2);
        verticalLine[0].position = sf::Vector2f(i * cellWidth, window.getSize().y / 2);
        verticalLine[1].position = sf::Vector2f(i * cellWidth, window.getSize().y);
        window.draw(verticalLine);
    }
}

sf::Vector2i Grid::getMouseGridPosition(sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    int gridX = static_cast<int>(mousePosition.x / (static_cast<float>(window.getSize().x) / numCols));
    int gridY = static_cast<int>((mousePosition.y - window.getSize().y / 2) / (static_cast<float>(window.getSize().y) / numRows));
    return sf::Vector2i(gridX, gridY);
}