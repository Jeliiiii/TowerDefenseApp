#include "Enemy.h"

Enemy::Enemy(Path* p)
{
	shape = new sf::CircleShape(10.f);
	shape->setFillColor(sf::Color::Black);
	shape->setOrigin(0.5f * 20.f, 0.5f * 20.f);

	shape->setPosition(sf::Vector2f(80*p->points[0].x+40, 80*p->points[0].y+40));
	last_point = sf::Vector2f(p->points[0].x, p->points[0].y);
	progress += 1;

	path = p;
}

Enemy::~Enemy()
{
	delete shape;
}

void Enemy::update()
{
	timer += 0.01f * speed;
	sf::Vector2f pos = shape->getPosition();
	//sf::Vector2f direction = path->points[progress] - last_point;
	if (timer <= 1.f)
	{
		float x = lerp(80 * last_point.x + 40, 80 * path->points[progress].x+40, timer);
		float y = lerp(80 * last_point.y + 40, 80 * path->points[progress].y + 40, timer);
		shape->setPosition(sf::Vector2f(x, y));
	}
	else {
		if (progress < path->points.size()-1)
		{
			last_point = sf::Vector2f(path->points[progress].x, path->points[progress].y);
			progress += 1;
			timer = 0;
		}
	}
}

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(*shape);
}

float Enemy::lerp(float start_value, float end_value, float time)
{
	return (start_value + (end_value - start_value) * time);
}