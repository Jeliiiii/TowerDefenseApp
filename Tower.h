#pragma once

#include <SFML/Graphics.hpp>

class Tower {
public:
    Tower();
    Tower(sf::Vector2f position); // Constructor with position
    ~Tower();

    void setPosition(sf::Vector2f position);
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape shape;
};