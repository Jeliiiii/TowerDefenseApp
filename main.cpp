#include "main.h"

int main()
{
    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Tower Defense");

    window.setVerticalSyncEnabled(true);

    while (window.isOpen())
    {

        Event event;

        vector<vector<int>> grid;
        for (int i = 0; i < 30; ++i)
        {
            for (int j = 0; j < 30; ++j)
            {
                grid.push_back(new int ());
            }
        }
        

        //EVENT
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
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