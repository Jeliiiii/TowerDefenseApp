#pragma once
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Map.h"

class Vague;

class GameManager
{
	public:
		sf::RenderWindow window;
		//Vague vague;

		GameManager(int w, int h);
		~GameManager();

		void loop();

	private:
		bool run = true;
		Map* map = new Map();

		void update();

		void draw();
};