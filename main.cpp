#include "GameManager.h"
#include <iostream>

using namespace sf;
using namespace std;

GameManager input;
Clock deltaClock;
float deltaTime = 0;

int main()
{

    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Tower Defense");
    window.setVerticalSyncEnabled(true);

    Event event;
    while (window.isOpen())
    {
		while (window.pollEvent(event))
		{
            input.InputHandler(event, window);
		}

		window.clear(Color::Black);

        window.display();

        deltaTime = deltaClock.restart().asSeconds();
	}


    return 0;
}