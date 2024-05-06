#include <SFML/Graphics.hpp>
#include <vector>
#include "grid.hpp"
using namespace sf;
using namespace std;

int numCells = 20;
int width = 500;
int height = 500;

int main()
{
    RenderWindow window(VideoMode(width, height), "SFML works!");
    window.setFramerateLimit(60);
    Grid grid(numCells, width, height);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }   if (event.type==Event::MouseButtonPressed){
            if (event.mouseButton.button==Mouse::Left)
            {
                int x=event.mouseButton.x; 
                int y=event.mouseButton.y; 
                grid.toggle(x,y); 
            }
        }

        window.clear();
        grid.drawTo(window);
        window.display();
    }

    return 0;
}