#pragma once
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class Resources
{

	sf::Text text;
	sf::Font font;

	char textbuffer[30];

	public:
		Resources();

		void addMoney(int value);
		void addGold(int value);

		bool spendMoney(int value);
		bool spendGold(int value);

		int getMoney();
		int getGold();

		void draw(sf::RenderWindow& window);
	private:
		int money = 0;
		int gold = 0;
};