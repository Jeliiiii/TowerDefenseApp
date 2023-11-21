#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Casse-briques");

    window.setVerticalSyncEnabled(true);

    while (window.isOpen())
    {
        //EVENT
        while (window.pollEvent(event))
        {

        }

        //UPDATE

        //DRAW
        window.clear(Color::Black);

        // C'est ici qu'on dessine les éléments du jeu   

        window.display();

        //End of loop
    }
    return 0;
}