#pragma once
#include "GameManager.h"

Game::Game()
{

}

void Game::DrawAll(vector<Cell*> objects, RenderWindow& window)
{
	for (int i = 0; i < objects.size(); ++i)
	{
		for (int j = 0; j < objects.size(); ++j)
		{
			window.draw(*objects[i]->getShape());
		}
	}
}