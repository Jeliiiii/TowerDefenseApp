#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Enemy {
public:
    Enemy(const std::vector<sf::Vector2i>& path, float speed);

    void move();
    void draw(sf::RenderWindow& window) const;
    bool hasReachedEnd() const;

private:
    const std::vector<sf::Vector2i>& path;
    sf::Vector2f position;
    float speed;
    size_t currentPathIndex;
    int cellSize;
};


