#include "Cell.h"
#include "main.h"

Cell::Cell(float x, float y, float w, float h, Color color)
{
	position.x = x;
	position.y = y;

	this->w = w;
	this->h = h;
	this->color = color;

	pShape = new RectangleShape(Vector2f(w, h));
	pShape->setFillColor(color);
	//pShape->setOrigin(w / 2.0f, h / 2.0f);
	pShape->setPosition(x, y);
};