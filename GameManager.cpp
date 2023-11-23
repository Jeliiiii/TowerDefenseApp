#include "GameManager.h"
#include <SFML/Graphics.hpp>

GameManager::GameManager(int w, int h)
{
    window.create(sf::VideoMode(w, h), "how are your balls");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    enemy = new Enemy(map->path);
}

GameManager::~GameManager()
{
    delete map;
    delete enemy;
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
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.scancode == sf::Keyboard::Scan::NumpadPlus)
                    resources->addMoney(9999);
                else if (event.key.scancode == sf::Keyboard::Scan::NumpadMinus)
                    resources->spendMoney(999);
                else if (event.key.scancode == sf::Keyboard::Scan::PageUp)
                    resources->addGold(9999);
                else if (event.key.scancode == sf::Keyboard::Scan::PageDown)
                    resources->spendGold(999);
            }
        }

        update();

        draw();
    }
}

void GameManager::update()
{
    enemy->update();
}

void GameManager::draw()
{
    window.clear();

    map->draw(window);

    enemy->draw(window);

    resources->draw(window);

    window.display();
}