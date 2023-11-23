#pragma once
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Enemy.h"
#include "Map.h"
#include "Resources.h"

class Vague;

class GameManager
{
	public:
		Enemy* enemy;
		sf::RenderWindow window;
		Resources* resources = new Resources();
		//Vague vague;

		GameManager(int w, int h);
		~GameManager();

		void loop();

	private:
		bool run = true;
		Map* map = new Map("testmap");

		void update();

		void draw();
};