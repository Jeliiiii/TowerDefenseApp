#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>


class GameObject
{
private:

	//bool wasCollidingLastFrame;

	float origineX;
	float origineY;

	float width;
	float height;

	float ancrageX;
	float ancrageY;

	float speed;

	sf::Color color;
	sf::Shape* graphic;

public:
	typedef struct RectDesc
	{
		float origineX;
		float origineY;
		float width;
		float height;
		float ancrageX = width / 2;
		float ancrageY = height / 2;
		float orientation = 0;
		float speed = 0;
		sf::Color color = sf::Color::Red;
	};

	typedef struct CircleDesc
	{
		float origineX;
		float origineY;
		float radius;
		float ancrageX = radius / 2;
		float ancrageY = radius / 2;
		sf::Color color = sf::Color::Blue;
	};

	GameObject(RectDesc desc);
	GameObject(CircleDesc desc);
	~GameObject();

	sf::Shape* GetRender();
};