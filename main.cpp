#include <SFML/Graphics.hpp>
#include "GameManager.h"

int main()
{
    GameManager* game = new GameManager(1280, 720);

    game->loop();

    delete game;
    return 0;
} 