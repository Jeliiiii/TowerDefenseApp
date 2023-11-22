#include "main.h"

int main()
{
    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Tower Defense");

    window.setVerticalSyncEnabled(true);

    vector<Cell*> grid;
    int x = 5;
    for (int i = 0; i < 23; i++)
    {
        int y = 5;
        for (int j = 0; j < 14; j++)
        {
            grid.push_back(new Cell(x, y, 50, 50, Color::Red));
            y = y + 55;
        }
        x = x + 55;
    }

    //Cell cell(5, 5, 50, 50, Color::Blue);

    while (window.isOpen())
    {

        Game jeu;
        Event event;

        //EVENT
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape))
            {
                window.close();
            }
        }

        //UPDATE

        //DRAW
        window.clear(Color::Black);
        jeu.DrawAll(grid, window);

        // C'est ici qu'on dessine les éléments du jeu   

        window.display();

        //End of loop
    }
    return 0;
}