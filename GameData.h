#pragma once
#include "Tower.h"
#include "Enemy.h"
#include <vector>

class GameData {
public:
    std::vector<Tower> towers;
    std::vector<Enemy> enemies;

    void CreateTower();
    void CreateEnemy();
    void CreateTowerAtPosition(float x, float y);
};
