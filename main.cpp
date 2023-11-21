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

    GameObject rect(200, 200, 50, 50, Color::Red);
    GameObject circ(300, 300, 10, 80, 300, Color::Yellow);


    Event event;
    while (window.isOpen())
    {
		while (window.pollEvent(event))
		{
            input.InputHandler(event, window);
		}

        circ.Move(deltaTime);
        circ.CheckWindowCollision();

		window.clear(Color::Black);

        window.draw(*circ.getShape());

        window.display();

        deltaTime = deltaClock.restart().asSeconds();
	}


    return 0;
}