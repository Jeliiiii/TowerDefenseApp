#include "GameObject.h"

GameObject::GameObject(float x, float y, float w, float h, Color color)
{
	position.x = x;
	position.y = y;

	this->w = w;
	this->h = h;
	this->color = color;

	pShape = new RectangleShape(Vector2f(w, h));
	pShape->setFillColor(color);
	pShape->setOrigin(w / 2.0f, h / 2.0f);
	pShape->setPosition(x, y);
};

GameObject::GameObject(float x, float y, float r, float orientation, float speed, Color color)
{

	this->r = r;
	this->orientation = orientation;
	this->speed = speed;
	this->color = color;

	w = r * 2;
	h = r * 2;

	pShape = new CircleShape(r);
	pShape->setFillColor(color);
	pShape->setOrigin(r, r);

	hitbox = new RectangleShape(Vector2f(w, h));
	hitbox->setOrigin(w / 2.0f, h / 2.0f);

	setPositionCircle(x, y);

	setRotationAngle(orientation);
};

void GameObject::setPositionCircle(float x, float y)
{
	position.x = x;
	position.y = y;

	pShape->setPosition(x, y);
	hitbox->setPosition(x, y);
}

void GameObject::setPositionRect(float x, float y)
{
	position.x = x;
	position.y = y;

	pShape->setPosition(x, y);
}

Vector2f GameObject::getPosition()
{
	return position;
}

Shape* GameObject::getHitbox()
{
	return this->hitbox;
}

void GameObject::setRotationAngle(float angle)
{
	orientation = angle;
	pShape->setRotation(angle);
	direction.x = sin(orientation * (M_PI / 180));
	direction.y = -1 * cos(orientation * (M_PI / 180));
}

void GameObject::Move(float deltaTime)
{
	float x = pShape->getPosition().x + direction.x * deltaTime * speed;
	float y = pShape->getPosition().y + direction.y * deltaTime * speed;

	setPositionCircle(x, y);
}

Shape* GameObject::getShape()
{
	return pShape;
}

void GameObject::VerticalBounce()
{
	direction.y = -direction.y;
}

void GameObject::HorizontalBounce()
{
	direction.x = -direction.x;
}

void GameObject::CheckWindowCollision()
{
	Vector2f position = pShape->getPosition();
	float halfWidth = w / 2.0f;
	float halfHeight = h / 2.0f;

	if (position.x - halfWidth <= 0)
	{
		std::cout << "LEFT" << std::endl;
		HorizontalBounce();
		position.x = halfWidth;
	}

	if (position.x + halfWidth >= WIN_WIDTH)
	{
		std::cout << "RIGHT" << std::endl;
		HorizontalBounce();
		position.x = WIN_WIDTH - halfWidth;
	}


	if (position.y - halfHeight <= 0)
	{
		std::cout << "TOP" << std::endl;
		VerticalBounce();
		position.y = halfHeight;
	}

	if (position.y + halfHeight >= WIN_HEIGHT)
	{
		std::cout << "BOTTOM" << std::endl;
		VerticalBounce();
		position.y = WIN_HEIGHT - halfHeight;
	}

	setPositionCircle(position.x, position.y);
}