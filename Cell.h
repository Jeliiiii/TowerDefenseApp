#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

class Cell
{
public :

	Cell(float x, float y, float w, float h, Color color);
	Shape* getShape();
	int getW();
	int getH();
	void DrawAll(vector<Cell*> objects, RenderWindow& window);

private :

	Shape* pShape;
	Vector2i position;
	float x;
	float y;
	float w;
	float h;
	Color color;
};

