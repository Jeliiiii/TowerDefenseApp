#pragma once

class Cell
{
public :

	Cell(float x, float y, float w, float h, Color color);

private :
	Shape* pShape;
	Vector2i position;
	float x;
	float y;
	float w;
	float h;
	Color color;
};

