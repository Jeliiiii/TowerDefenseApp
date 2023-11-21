#include "Enemy.h"

Enemy::Enemy(float startX, float startY, float speed) : speed(speed)
{
	shape.setRadius(30);
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(startX, startY);
}

void Enemy::update(float deltaTime)
{
	float distance = speed * deltaTime;

	shape.move(distance, distance);
}

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}