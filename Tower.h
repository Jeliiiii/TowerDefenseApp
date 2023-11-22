#pragma once

#include <SFML/Graphics.hpp>

class Tower {
public:
    Tower(const sf::Vector2f& position);
    ~Tower();

    
    void draw(sf::RenderWindow& window) const;

private:
    sf::RectangleShape shape;
};