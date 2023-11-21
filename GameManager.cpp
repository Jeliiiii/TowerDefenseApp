#include "GameManager.h"
#include <SFML/Graphics.hpp>

GameManager::GameManager(int w, int h)
{
    window.create(sf::VideoMode(w, h), "how are your balls");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
}

GameManager::~GameManager()
{
    delete map;
}

void GameManager::loop()
{
    while (run && window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
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