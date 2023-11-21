#pragma once

#include <SFML/Graphics.hpp>

class Enemy {
public:

    Enemy(float startX, float startY, float speed);  // Constructor
    void update(float deltaTime);  // Update method for movement
    void draw(sf::RenderWindow& window);  // Render method

private:

    sf::CircleShape shape;
    float speed;
};