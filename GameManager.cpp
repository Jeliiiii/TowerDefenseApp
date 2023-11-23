#include "GameManager.h"

GameManager::GameManager() {
}
GameManager::~GameManager() {
}

void GameManager::Launch() {


    sf::RenderWindow window(sf::VideoMode(screen.x, screen.y), "Tower Defense");

    gameData.CreateTower();
    gameData.CreateEnemy();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Gérer les clics de souris
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Créer une tour à l'emplacement du clic
                    gameData.CreateTowerAtPosition(event.mouseButton.x, event.mouseButton.y);
                }
            }
        }

        window.clear(sf::Color::Green);
        for (auto& tower : gameData.towers) {
            window.draw(*tower.GetRender());
            window.draw(*tower.GetZoneDamage());
        }
        for (auto& enemy : gameData.enemies) {
            window.draw(*enemy.GetRender());
        }
        window.display();
    }
}
