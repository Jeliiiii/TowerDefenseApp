#include "GameData.h"

void GameData::CreateEnemy() {
    GameObject::RectDesc EnemyDesc = { 250, 250, 50, 50, 25, 25, sf::Color::Blue };

    Enemy enemy(EnemyDesc, 10);
    enemies.push_back(enemy);
}

void GameData::CreateTower() {
    GameObject::CircleDesc TowerDesc = { 100, 100, 50, 25, 25, sf::Color::Red };

    Tower tower(TowerDesc, 10, 75);
    towers.push_back(tower);
}

void GameData::CreateTowerAtPosition(float x, float y) {
    GameObject::CircleDesc TowerDesc = { x, y, 50, 25, 25, sf::Color::Red };
    Tower tower(TowerDesc, 10, 50);
    towers.push_back(tower);
}