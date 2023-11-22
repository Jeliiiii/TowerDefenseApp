#include "GameManager.h"

GameManager::GameManager() {
}
GameManager::~GameManager() {
}

void GameManager::Launch() {


    sf::RenderWindow window(sf::VideoMode(screen.x, screen.y), "SFML works!");
    CreateTower();
    CreateEnemy();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Green);
        for (auto it = towers.begin(); it != towers.end(); ++it) {
            window.draw(*it->GetRender());
        }
        for (auto it = enemies.begin(); it != enemies.end(); ++it) {
			window.draw(*it->GetRender());
		}
        window.display();
    }
}

void GameManager::CreateEnemy() {
    GameObject::RectDesc EnemyDesc = { 250, 250, 50, 50, 25, 25, 0, sf::Color::Blue };

    Enemy enemy(EnemyDesc, 10);
    enemies.push_back(enemy);
}

void GameManager::CreateTower() {
    GameObject::CircleDesc TowerDesc = { 100,100, 50, 25,25, sf::Color::Red };

    Tower tower(TowerDesc, 10, 50);
    towers.push_back(tower);
}
