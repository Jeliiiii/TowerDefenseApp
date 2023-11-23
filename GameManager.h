#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameData.h"

class GameManager
{
private:
    sf::Vector2f screen = { 1280,720 };
    GameData gameData; // GameData est une classe qui contient les vecteurs de tours et d'ennemis

public:
    sf::RenderWindow window;

    GameManager();
    ~GameManager();
    void Loop();
};
