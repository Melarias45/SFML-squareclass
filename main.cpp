#include <SFML/Graphics.hpp>
#include "rectangle.hpp"
using namespace sf;


Vector2f speed={5.f,5.f};

int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60); //para que no se mueva tan rapido, porque la compu ejecuta muchisimos frames por segundo de texto. 
    Rectangle shape (Vector2f(50.f,50.f)); 

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        // window.clear(); //si podemos antes lo de mover, se va a ver como barrido y no irse borrando para dar la ilusion de que se esta moviendo la figura. 
        
        window.clear(); //si se quita quedaria un rastro de la figura. 
        shape.update(); //actualiza
        shape.drawTo(window); //dibuja la ventana 
        window.display();
    }

    return 0;
}