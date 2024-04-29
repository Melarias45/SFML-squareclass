#include <SFML/Graphics.hpp>
#include <vector>
#include "grid.hpp"
using namespace sf;
using namespace std; 

int main()
{
    RenderWindow window(VideoMode(200, 200), "SFML works!");
    window.setFramerateLimit(60); 
    Grid grid (5,5); 
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();


        }

        window.clear();
        grid.drawTo(window); 
        window.display();
    }

    return 0;
}