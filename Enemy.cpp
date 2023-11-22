#include "Enemy.h"

Enemy::Enemy(const std::vector<sf::Vector2i>& path, float speed)
    : path(path), speed(speed), currentPathIndex(0) {
    position.x = path[0].x * cellSize; // Assuming cellSize is the size of each cell on the grid
    position.y = path[0].y * cellSize;
}

void Enemy::move() {
    if (currentPathIndex < path.size() - 1) {
        sf::Vector2f target(path[currentPathIndex + 1].x * cellSize, path[currentPathIndex + 1].y * cellSize);
        sf::Vector2f direction = target - position;
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

        if (length > 0.0f) {
            direction /= length;
            position += direction * speed;
        }

        if (position == target) {
            ++currentPathIndex;
        }
    }
}

void Enemy::draw(sf::RenderWindow& window) const {
    sf::CircleShape enemyShape(20.0f); // Adjust the size as needed
    enemyShape.setFillColor(sf::Color::Red);
    enemyShape.setPosition(position);
    window.draw(enemyShape);
}

bool Enemy::hasReachedEnd() const {
    return currentPathIndex == path.size() - 1;
}
