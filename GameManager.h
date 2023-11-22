#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tower.h"
#include "Enemy.h"

class GameManager
{
private:
    sf::Vector2f screen = { 1280,720 };
    std::vector<Tower> towers;
    std::vector<Enemy> enemies;

public:
    GameManager();
    ~GameManager();
    void Launch();
    void CreateTower();
    void CreateEnemy();
};
