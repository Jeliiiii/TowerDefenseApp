#include "Resources.h"
#include <iostream>
using namespace std;

Resources::Resources()
{
	cout << font.loadFromFile("arial.ttf") << endl;
	text.setFont(font);

	snprintf(textbuffer, sizeof(textbuffer), "Money: %i\nGold: %i", money, gold);
	text.setString(textbuffer);
	text.setCharacterSize(32);
	text.setFillColor(sf::Color::Black);
	text.setPosition(5, 720 - 75);
}

void Resources::addMoney(int value)
{
	money += value;
	snprintf(textbuffer, sizeof(textbuffer), "Money: %i\nGold: %i", money, gold);
	text.setString(textbuffer);
}

void Resources::addGold(int value)
{
	gold += value;
	snprintf(textbuffer, sizeof(textbuffer), "Money: %i\nGold: %i", money, gold);
	text.setString(textbuffer);
}

bool Resources::spendMoney(int value)
{
	if (money < value)
		return false;
	money -= value;
	snprintf(textbuffer, sizeof(textbuffer), "Money: %i\nGold: %i", money, gold);
	text.setString(textbuffer);
	return true;
}

bool Resources::spendGold(int value)
{
	if (gold < value)
		return false;
	gold -= value;
	snprintf(textbuffer, sizeof(textbuffer), "Money: %i\nGold: %i", money, gold);
	text.setString(textbuffer);
	return true;
}

int Resources::getMoney()
{
	return money;
}

int Resources::getGold()
{
	return gold;
}

void Resources::draw(sf::RenderWindow& window)
{
	window.draw(text);
}