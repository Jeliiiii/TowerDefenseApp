// main.cpp
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemy.h"  
#include "Tower.h"
#include "Grid.h"

using namespace sf;


int main() {

    

    VideoMode desktop = VideoMode::getDesktopMode();
    RenderWindow window(VideoMode(desktop.width, desktop.height), "SFML Tower Defense");

    Enemy enemy(100, 100, 100.0f);
    Tower tower;
    Grid grid(5, 10, window);

    Clock clock;

    float deltaTime = 0.f;


    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape)
                    window.close();
            }
        }

        enemy.update(deltaTime);

        window.clear();

        grid.handleInput(window);
        grid.draw(window);
        enemy.draw(window);
        tower.draw(window);

        window.display();

        deltaTime = clock.restart().asSeconds();
    }

    return 0;
}
