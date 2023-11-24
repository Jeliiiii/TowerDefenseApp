#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameData.h"

class GameManager
{
private:
    sf::Vector2f screen = { 1280,720 };
    GameData gameData;

public:
    sf::RenderWindow window;

    GameManager();
    ~GameManager();
    void Loop();
};
