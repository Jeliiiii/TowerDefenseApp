#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tower.h"

class GameManager
{
private:
    sf::Vector2f screen = { 1280,720 };
    std::vector<Tower> towers;

public:
    GameManager();
    ~GameManager();
    void Launch();
    void CreateTower();
};
