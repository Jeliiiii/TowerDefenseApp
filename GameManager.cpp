#include "GameManager.h"

GameManager::GameManager() {
    window.create(sf::VideoMode(screen.x, screen.y), "Tower Defense");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
}
GameManager::~GameManager() {
}

void GameManager::Loop() {

    //gameData.CreateTower(); Test de cr�ation de tour
    //gameData.CreateEnemy(); Test de cr�ation d'ennemi

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // G�rer les clics de souris
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Cr�er une tour � l'emplacement du clic
                    gameData.CreateTowerAtPosition(event.mouseButton.x, event.mouseButton.y);
                }
            }
        }

        window.clear(sf::Color::Green);

        gameData.CreateMap(window);

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
