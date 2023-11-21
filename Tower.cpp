#include "Tower.h"

Tower::Tower()
{
	shape.setSize(sf::Vector2f(50, 50));
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(100, 100);
}

//void Tower::update()
//{
//	// Shoot every 10 frames
//	if (frameCounter % 10 == 0)
//	{
//		// Create a bullet
//		Bullet b;
//		b.shape.setPosition(shape.getPosition().x + shape.getSize().x / 2, shape.getPosition().y);
//		bullets.push_back(b);
//	}
//
//	// Move all bullets
//	for (size_t i = 0; i < bullets.size(); i++)
//	{
//		bullets[i].shape.move(0, -5);
//	}
//
//	frameCounter++;
//}

void Tower::draw(sf::RenderWindow& window)
{
	window.draw(shape);

	//// Draw all bullets
	//for (size_t i = 0; i < bullets.size(); i++)
	//{
	//	window.draw(bullets[i].shape);
	//}
}