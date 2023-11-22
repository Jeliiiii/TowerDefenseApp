#pragma once
#include "Cell.h"

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

Shape* Cell::getShape()
{
	return pShape;
};

int Cell::getW()
{
	return this->w;
}

int Cell::getH()
{
	return this->h;
}

void Cell::DrawAll(vector<Cell*> objects, RenderWindow& window)
{
	for (int i = 0; i < objects.size(); ++i)
	{
		for (int j = 0; j < objects.size(); ++j)
		{
			window.draw(*objects[i]->getShape());
		}
	}
}