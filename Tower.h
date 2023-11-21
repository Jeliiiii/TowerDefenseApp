#pragma once

#include <SFML/Graphics.hpp>

class Tower {
public:
    Tower();  // Constructor
    //void update();  // Update method for shooting logic
    void draw(sf::RenderWindow& window);  // Render method
private:
    sf::RectangleShape shape;
    // Other necessary properties
};