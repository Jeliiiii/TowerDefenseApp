#pragma once
#include "SFML/Graphics/CircleShape.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Path.h"

class Enemy
{
	sf::CircleShape* shape;
	Path* path;
	sf::Vector2f last_point;
	float timer = 0;
	int progress = 0;
	float speed = 4.f;

	public:
		Enemy(Path* p);
		~Enemy();

		void update();
		void draw(sf::RenderWindow& window);

	private:
		float lerp(float start_pos, float end_pos, float time);
};