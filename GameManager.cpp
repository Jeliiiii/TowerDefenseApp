#include "GameManager.h"

GameManager::GameManager()
{
}

void GameManager::InputHandler(Event event, RenderWindow& window)
{
	if (event.type == Event::Closed)
	{
		window.close();
	}

	if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape))
	{
		window.close();
	}
}