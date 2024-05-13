#include <SFML/Graphics.hpp>

#include <iostream>
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60); 

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

       
        
        window.clear(); 
        window.display();
    }

    return 0;
}