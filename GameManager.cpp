#include "GameManager.h"

GameManager::GameManager() {
}
GameManager::~GameManager() {
}

void GameManager::Launch() {


    sf::RenderWindow window(sf::VideoMode(screen.x, screen.y), "SFML works!");

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
        window.display();
    }
}

void GameManager::CreateTower() {
    GameObject::CircleDesc TowerDesc = { 100,100, 50, 25,25, sf::Color::White};

    Tower tower(TowerDesc);
    towers.push_back(tower);
}