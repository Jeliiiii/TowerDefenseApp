#pragma once
#include "Tower.h"
#include "Enemy.h"
#include "Map.h"
#include <vector>

class GameData {
public:
    std::vector<Tower> towers;
    std::vector<Enemy> enemies;

    Map gameMap;

    void CreateTower();
    void CreateEnemy();
    void CreateTowerAtPosition(float x, float y);
    bool isTowerAtPosition(int gridX, int gridY) const;
    void CreateMap(sf::RenderWindow& window);
};
