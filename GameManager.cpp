#include "GameManager.h"
#include <SFML/Graphics.hpp>

GameManager::GameManager(int w, int h)
{
    window.create(sf::VideoMode(w, h), "Tower Defender");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
}

GameManager::~GameManager()
{
    delete map;
}

void GameManager::loop()
{
    int cellSize = 80;
    Map gameMap;
    while (run && window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
					window.close();
				}
			}

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                int cellX = mousePosition.x / cellSize;
                int cellY = mousePosition.y / cellSize;
                gameMap.placeTower(cellX, cellY);
            }
        }

        update();

        draw();
    }
}

void GameManager::update()
{

}

void GameManager::draw()
{
    window.clear();

    map->draw(window);

    window.display();
}